/***********************************************
File: Provider.h
Author: Josue Ballona
Logon ID: z1832823
Due Date: September 26

Purpose: Declaration for the Provider class,
                        which represents information about a
                        health care provider
**************************************************/
#ifndef PROVIDER_H
#define PROVIDER_H

class Provider
{
private:
        char provnum[6];
        char specialty[40];
        char name[40];
        char add1[40];
        char add2[30];
        char city[20];
        char state[2];
        char zip[5];
        char phone[14];
public:
        Provider();
        void print() const;
        const char * getProviderNumber() const;
        const char * getSpecialty() const;
        const char * getName() const;

};



#endif
