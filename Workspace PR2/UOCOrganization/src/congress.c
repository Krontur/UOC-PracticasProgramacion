#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "congress.h"
#include <string.h>
#include "organization.h"
#include "presentation.h"

// Initialize the congress
void congress_init(tCongress* object, char* name) {
    // PR1 EX4
    
    // Verify pre conditions
    assert(object != NULL);    
    assert(name != NULL);
    
    // Allocate the memory for congress name, using the length of the provided text plus 1 space for the "end of string" char '\0'. To allocate memory we use the malloc command.    
    object->name = (char*) malloc((strlen(name) + 1) * sizeof(char));   
    strcpy(object->name, name);  
   
    object->organizations = (tOrganizationTable*) malloc(sizeof(tOrganizationTable)) ;     
    // Initialize organizations
    organizationTable_init(object->organizations);  

    // PR2 EX1 
    /*********	Initialize presentations queue	*************/
    // TODO 
	presentationQueue_createQueue(&object->presentations);
}

// Remove all data for a congress
void congress_free(tCongress* object) {
    // PR1 EX4
    assert(object!=NULL);
    // Remove data from organizations table
    organizationTable_free(object->organizations);
    
    // PR2 EX2    
    /************	Remove data from presentations queue	************/
    // TODO
	presentationQueue_free(&object->presentations);
}

// Register a new organization
tError congress_registerOrganization(tCongress* object, tOrganization* organization) {

    // PR1 EX4    
    assert(object != NULL);   
    assert(organization != NULL);   
    
    tError err;
    
    // Check if the organization already exists
    int i;
    for(i=0; i < object->organizations->size;i++)
    {   
        if(organizationTable_find(object->organizations, organization->name) != NULL) {
            return ERR_DUPLICATED;
        }
    }
    
    // Add the organization to the table
    err = organizationTable_add(object->organizations, organization);
    
    return err;    
}

// Remove a organization
tError congress_removeOrganization(tCongress* object, tOrganization* organization) {
    // PR1 EX4
    assert(object != NULL); 
    assert(organization != NULL); 
    
    // Get the organization with the organizationName
    organization = organizationTable_find(object->organizations, organization->name);
    
    if(organization == NULL) {
        return ERR_NOT_FOUND;
    }
    
    return organizationTable_remove(object->organizations, organization);
}

// Find a organization
tOrganization* congress_findOrganization(tCongress* object, const char* organizationName) {
    // PR1 EX4   
    assert(object != NULL); 
    assert(organizationName != NULL);
 
    return organizationTable_find(object->organizations, organizationName);
}


tError congress_getGuests(tCongress* object, tGuestTable* guests) {
    // PR1 EX4

    assert(object != NULL);
    assert(guests != NULL);    

    int i, j;
    tError error;
    error = OK;    

    for (i=0; i<object->organizations->size; i++) {
        for (j=0; j<object->organizations->elements[i].guests->size; j++) {
            error = guestTable_add(guests, &(object->organizations->elements[i].guests->elements[j]));
        }
    }   
    return error;
}


/**************	Add a new presentation	*******************/
tError congress_addPresentation(tCongress* object, const char* organization_name, double score, const char* presentationTitle, const char* presentationTopic) {
    // PR2 EX1
    //return ERR_NOT_IMPLEMENTED;
	
	tOrganization *organization;
	tPresentation presentation;
	
	organization = congress_findOrganization(object, organization_name);
	if(organization == NULL){
		return ERR_INVALID_ORGANIZATION; //if the organization isn't found in congress return the error
	}
	// else initialize the presentation with the input parameters
	presentation_init(&presentation, organization, score, presentationTitle, presentationTopic);
	//and enqueue the presentation in the queue presentations
	return presentationQueue_enqueue(&(object->presentations), presentation);
}


/**********	Get if an organization wins on a topic. Wins means best score on a topic	****************/
int congress_getOrganizationWins(tCongress* object, const char* organization_name, const char* topic) {
    // PR2 EX2
    //return ERR_NOT_IMPLEMENTED;
	
	//Check preconditions
	assert(object != NULL);
	assert(organization_name != NULL);
	assert(topic != NULL);
		
	tPresentation p1, p2;
	tOrganization *organization;
	tPresentationQueue presentations;
	
	p1.presentationTopic = "empty";
	p2.presentationTopic = "empty"; //Presentation are empty.
	
	organization = congress_findOrganization(object, organization_name);
	if(organization == NULL){
		return ERR_NOT_EXISTS; //if the organization isn't found return the error.
	}
	
	//the queue is duplicated to work with the copy
	presentationQueue_duplicate(&presentations, object->presentations);
	
	while(!presentationQueue_empty(presentations)){
		tPresentation *pTemp;
		pTemp = presentationQueue_head(presentations);
		
		// if the variable presentationTopic and organization's name of the element on the head of the duplicated queue match
		if(strcmp(pTemp->presentationTopic, topic) == 0){
			if(strcmp(pTemp->organization.name, organization_name) == 0){
				//the presentation from the element on the head of the queue is pointed by p1
				presentation_duplicate(&p1, *pTemp);
				//the element on the head of the queue is deleted
				presentationQueue_dequeue(&presentations);
				continue;
			} else {
				if(pTemp->score > p2.score){		//if score of the element of the head is bigger than the score of p2
					presentation_duplicate(&p2, *pTemp); //the element pTemp is duplicated(or overwritten) to the variable p2
				} 
			}
		}
		//in any other case the element on the head is deleted
		presentationQueue_dequeue(&presentations);
	}
	//the results are compared and a value is returned for every case.
	if(strcmp(p1.presentationTopic, "empty") != 0 || strcmp(p2.presentationTopic, "empty") != 0){
		if(p1.score > p2.score){
			return 3;
		}
		if(p1.score == p2.score){
			return 1;
		} else {
			return 0; // p1.score is smaller than p2.score
		}
	} else {
		return ERR_NOT_EXISTS; // Topic not found.
	}
} 


/***************	Get the average score for an organization	*******************/
double congress_getOrganizationScore(tCongress* object, const char* organization_name) {
    // PR2 EX3
	//return ERR_NOT_IMPLEMENTED;
	
	//Check preconditions
    assert(object != NULL);
	assert(organization_name != NULL);
	
	double result = 0; //we initialize the variable result to 0
	
	tOrganization *org;
	org = congress_findOrganization(object, organization_name); //the organization is searched
	if(org != NULL){ //if the organization is found
		//the recursive function is called und the value is saved in result
		result = presentationQueue_getOrganizationScoreRecursive(&(object->presentations), org);
	} else {
		result = 0; //if the organization isn't found is saved the value 0 in the variable result
	}
	return result;
}


/***************	Get a queue with all the presentations for an organization	*******************/
tError congress_getOrganizationPresentations(tCongress* object, const char* organization_name, tPresentationQueue* presentations) {
    // PR2 EX3
	//return ERR_NOT_IMPLEMENTED;
	
	//Check preconditions
	assert(object != NULL);
	assert(organization_name != NULL);
	assert(presentations != NULL);
	
	tOrganization *org;
	org = congress_findOrganization(object, organization_name); //the organization is searched
	if(org == NULL){	//if the organization isn't found
		return ERR_INVALID_ORGANIZATION;
	}
	//the recursive function is called with the parameters presentations of congres, the organization und the destination queue
	return presentationQueue_getOrganizationPresentationsRecursive(&(object->presentations), org, presentations);
	
}