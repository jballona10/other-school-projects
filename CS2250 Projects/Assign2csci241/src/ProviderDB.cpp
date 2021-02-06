#include "ProviderDB.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>

using std::strcmp;
using std::ifstream;
using std::ios;
using std::cout;
using std::endl;


ProviderDB::ProviderDB()
{
        numOfObj = 0;
        numOfObj++;
}

ProviderDB::ProviderDB(const char * dbFileName)
{
        numOfObj = 0;
        ifstream inFile;
        inFile.open(dbFileName, ios::binary);
        assert(dbFileName);

        inFile.read((char *) this, sizeof(ProviderDB));

        inFile.close();
        numOfObj++;

}

void ProviderDB::print() const
{
        cout << "Health Care Provider Listing" << endl;
        for (int i = 0; i < numOfObj; i++)
                provarr[i].print();
}

void ProviderDB::sortByProviderNumber()
{
        int i, j;
        Provider bucket;

        for (i = 1; i < numOfObj; i++)
        {
                bucket = provarr[i];

                for (j = i; (j > 0) && (strcmp(provarr[j-1].getProviderNumber(), bucket.getProviderNumber()) > 0); j--)
                {
                        provarr[j] = provarr[j-1];
                }

                provarr[j] = bucket;
        }
}

void ProviderDB::sortBySpecialty()
{
        int i, j;
        Provider bucket;

        for (i = 1; i < numOfObj; i++)
        {
                bucket = provarr[i];

                for (j = i; (j > 0) && (strcmp(provarr[j-1].getSpecialty(), bucket.getSpecialty()) < 0); j--)
                        provarr[j] = provarr[j-1];

                provarr[j] = bucket;
        }
}

void ProviderDB::sortByName()
{
        int i, j;
        Provider bucket;

        for (i = 1; i < numOfObj; i++)
        {
                bucket = provarr[i];

                for (j = i; (j > 0) && (strcmp(provarr[j-1].getName(), bucket.getName()) > 0); j--)
                        provarr[j] = provarr[j-1];

                provarr[j] = bucket;
        }
}
