/***********************************************************
 * File: Provider.cpp
 * Author: Josue Ballona
 * Logon ID: z1832823
 * Due Date: september 26
 *
 * Purpose: implementation of the provider class
 *************************************************************/
#include "Provider.h"
#include <iostream>
using std::cout;
using std::endl;

Provider::Provider()
{
        provnum[0] = '\0';
        specialty[0] = '\0';
        name[0] = '\0';
        add1[0] = '\0';
        add2[0] = '\0';
        city[0] = '\0';
        state[0] = '\0';
        zip[0] = '\0';
        phone[0] = '\0';
}

void Provider::print() const
{
        cout << "#" << provnum << endl << name << endl;
        cout << specialty << endl << add1 << endl << add2 << endl;
        cout << city << ", " << state << " " << zip << endl;
        cout << phone << endl;
}

const char * Provider::getProviderNumber() const
{
        return provnum;
}

const char * Provider::getName() const
{
        return name;
}

const char * Provider::getSpecialty() const
{
        return specialty;
}
