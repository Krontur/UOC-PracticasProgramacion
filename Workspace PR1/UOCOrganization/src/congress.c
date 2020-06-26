#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <strings.h>
#include "congress.h"
#include "organization.h"

/*****************************************************************
 * Oscar González Tur
 * Ingeniería Informatica
 * Curso 2018/19
 *****************************************************************/

/************* Initialize the congress *************/
void congress_init(tCongress* object, char* name)
{
    // PR1 EX4
	//Verify pre conditions
	assert(object != NULL);
	assert(name != NULL);
	
	//Allocate the memory for all the fields, using the length of the provided text plus 1 space for the "end of string" char '\0'.
	// To allocate memory we use the malloc command.
	object->name = (char*) malloc(strlen(name)+1 * sizeof(char));
	object->organizations = (tOrganizationTable*) malloc(sizeof(tOrganizationTable));
	
	//Check that memory has been allocated for all fields. Pointer must be different from NULL.
	if(object->name == NULL || object->organizations == NULL){
		//Some of the fields have a NULL value, what means the we found some problem allocating the memory
		fprintf(stderr, "Memory error, some of the fields have a NULL value, exiting...");
		exit (-1);
	}
	
	//Once the memory is allocated, copy the data. For the fields name we use the string copy function strcpy.
	strcpy(object->name, name);
	//initialize the table organizations empty.
	organizationTable_init(object->organizations);
	
    //return ;
}

/************* Remove all data for a congress *************/
void congress_free(tCongress* object) {
    // PR1 EX4
	//Verify pre conditions
	assert(object != NULL);
	
	// All memory allocated with malloc and realloc needs to be freed using the free command. In this case, as we use malloc to allocate the fields, we have to free them
    if(object->name != NULL) {
        free(object->name);
        object->name = NULL;
    }
    if(object->organizations != NULL) {
        free(object->organizations);
        object->organizations = NULL;
    }
    //return ;
}

/************* Register a new organization *************/
tError congress_registerOrganization(tCongress* object, tOrganization* organization) {
    // PR1 EX4
	//Verify pre conditions
	assert(object != NULL);
	assert(organization != NULL);
	//the organization is added in the organization's table (organizations)
	return organizationTable_add(object->organizations, organization);
	
    //return ERR_NOT_IMPLEMENTED;
}

/************* Remove a organization *************/
tError congress_removeOrganization(tCongress* object, tOrganization* organization) {
    // PR1 EX4
	//Verify pre conditions
	assert(object != NULL);
	assert(organization != NULL);
	//the organization is removed from the table organizations
	return organizationTable_remove(object->organizations, organization);
	
    //return ERR_NOT_IMPLEMENTED;
}

/************* Find a organization *************/
tOrganization* congress_findOrganization(tCongress* object, const char* organizationName) {
    // PR1 EX4
	//Verify pre conditions
	assert(object != NULL);
	assert(organizationName != NULL);
	//the function search an organization with the organizationName in the organization's table
	return organizationTable_find(object->organizations, organizationName);
	
    //return NULL;
}

/************** Get the guests of the congress ****************/
tError congress_getGuests(tCongress* object, tGuestTable* guests)
{
    // PR1 EX4
	int i,j;
	tError error;
	//Verify pre conditions
	assert(object != NULL);
	assert(guests != NULL);
	//we search the guests in every organization
	for(i=0; i<object->organizations->size; i++){
		for(j=0; j< object->organizations->elements[i].guests->size ; j++){
			//we add every guest to the guests Table, if is not duplicated
			error = guestTable_add(guests, &object->organizations->elements[i].guests->elements[j]);
			if(error == ERR_MEMORY_ERROR){
				return ERR_MEMORY_ERROR;
			} else if(error == ERR_DUPLICATED){
				//if the guest is duplicated, is not added to the table.
				continue;
			}	
		}
	}
	return OK;
    //return ERR_NOT_IMPLEMENTED;
}
