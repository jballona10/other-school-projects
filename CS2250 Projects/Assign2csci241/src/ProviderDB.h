/*******************************************************************
 * File: ProviderDB.h
 * Author: Josue Ballona
 * Logon ID: z1832823
 * Due Date: september 26
 *
 * Purpose: declaration for the ProviderDB class, which represents
 *                      a database of provider objects.
 *****************************************************************/
#ifndef PROVIDERDB_H
#define PROVIDERDB_H

#include "Provider.h"
#include <fstream>
#include <cassert>
#include <iostream>

class ProviderDB
{
private:
        Provider provarr[39];
        int numOfObj;
public:
        ProviderDB();
        ProviderDB(const char *);
        void print() const;
        void sortByProviderNumber();
        void sortBySpecialty();
        void sortByName();
};



#endif
