//============================================================================
// Name : Assign2csci241.cpp // Author : // Version : // Copyright :
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "Provider.h"
#include "ProviderDB.h"

using std::cout;
int main()
{
        ProviderDB provdb("providers.txt");
        provdb.print();

      //  provdb.sortByProviderNumber();
       // provdb.print();

        //provdb.sortBySpecialty();
        //provdb.print();

        //provdb.sortByName();
        //provdb.print();
}
