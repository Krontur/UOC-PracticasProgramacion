#ifndef __CONGRESS_H__
#define __CONGRESS_H__

#include "guest.h"
#include "organization.h"

// Definition of a congress
typedef struct {
	char* name;
    tOrganizationTable* organizations;
} tCongress;

// Initialize the congress
void congress_init(tCongress* object, char* name);

// Remove all data for a congress
void congress_free(tCongress* object);

// Register a new organization to the congress
tError congress_registerOrganization(tCongress* object, tOrganization* organization);

// Remove an organization from the congress
tError congress_removeOrganization(tCongress* object, tOrganization* organization);

// Find an organization
tOrganization* congress_findOrganization(tCongress* object, const char* organizationName);

// Get guests all gests of a congress
tError congress_getGuests(tCongress* object, tGuestTable* guests);

#endif // __CONGRESS_H__