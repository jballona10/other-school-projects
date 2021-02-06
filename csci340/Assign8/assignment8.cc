/**********************************************
* Josue Ballona
* CSCI 340 Section 2
* Z1832823
* April 13
* Assignment 8
* Write a program to create, search, print, and 
* manage an item inventory
************************************************/


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "assignment8.h"

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ios;
using std::cerr;

/**************************************
* HT is the constructor for the hash table. 
* It was an integer parameter representing the 
* size (initially set to 11
*****************************************/
HT::HT(int s = 11)
{
	hTable = new std::vector<Entry>(20);

	table_size = s;
	item_count = 0;
	
}

/*******************************************
* ~HT is the destructor for the hash table.
* Deletes the dynamically allocated vector
* from the constructor
********************************************/
HT::~HT()
{
	delete hTable;
}

/********************************************
* Search looks for a given key and returns 
* position of found item or -1.
* Takes in a reference to a const string
* representing th key 
********************************************/
int HT::search(const string & key)
{
	int hv = hashing(key);
	int count = 0;

	while(count != table_size)
	{
		if((*hTable)[hv].key == key)
			return hv;
		hv++;
		count++;
		hv %= table_size;
	}
	return -1;
}

/*****************************************
* insert inserts an in item into the hash
* table.  Takes a reference to a const Entry
* that is the item we want to insert and returns 
* a bool, true if the value was inserted
*******************************************/
bool HT::insert(const Entry & e)
{
	int hv = hashing(e.key);
	int probe;
	int s = search(e.key);
	if ((*hTable)[hv].key == "+++" || (*hTable)[hv].key == "---")
	{
		(*hTable)[hv] = e;
		probe = -1;
	}
	else
	{
		if (hv == (table_size - 1))
			probe = 0;
		else
			probe = hv + 1;
	}
	if (s != -1)
	{
		cout << "The key already exists.\n";
		return false;
	}
	
	if (item_count == table_size)
	{
		cout << "The table is full.\n";
		return false;
	} 
	
	while (probe != -1 && probe != hv) 
	{ 
		if ((*hTable)[probe].key == "+++" || (*hTable)[probe].key == "---")
		{
			(*hTable)[probe] = e;
			probe = -1;
		}
		else
		{
			if (probe == table_size - 1)
				probe = 0;
			else
				probe++;
		}
	}

	if (probe != -1)
		return false;
	return true;
}

/*****************************************************
* remove removes an item with a key given
* takes a reference to a const string representing key
* we want to delete. Returns true if item removed
******************************************************/
bool HT::remove(const string & s)
{
	int remsearch = search(s);

	//if (remsearch == -1)
		//return false;
	if ((*hTable)[remsearch].key == s)
	{
		(*hTable)[remsearch].key = "+++";
		item_count--;
		return true;
	}
	return false;
}

/******************************************************
* print prints the existing entries in the hash table,
* the index value, the key, and the description
********************************************************/
void HT::print()
{
	cout << "----Hash Table----\n";

	for (int i = 0; i < table_size; i++)
	{
		if ((*hTable)[i].key != "---" && (*hTable)[i].key != "+++")
			cout << i << ": " << (*hTable)[i].key << " " <<(*hTable)[i].description << endl;
	}
	cout << "-------------------\n";

}
// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size
int HT::hashing(const string& key) {
   return ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
}

/*****************************************************
* get_entry takes a line of input and parses it to create
* a new Entry. It takes a reference to a const string 
* representing the line of input and returns an Entry ptr
*******************************************************/
Entry * get_entry(const string & line)
{
	std::stringstream ss(line);
	Entry * e = new Entry;
	int sep = 0;
	string temp;

	while (getline(ss, temp, ':'))
	{
		if (sep == 1)
		{
			e->key = temp;
		}
		if (sep == 2)
			e->description = temp;

		sep++;
	}

	return e;

}

/*********************************************************
* get_key takes a line of input and parses it to return the
* item key. It takes a reference to a string const representing
* the line of input from the input file
************************************************************/
string get_key(const string & line)
{
	std::stringstream ss(line);

	int sep = 0;
	string temp;
	string key;

	while (getline(ss, temp, ':'))
	{
		if (sep == 1)
			key = temp;
		sep++;
	}

	return key;

}

int main(int argc, char** argv ) {
    if ( argc < 2 ) {
        cerr << "argument: file-name\n";
        return 1;
    }

    HT ht;
    ifstream infile(argv[1], ios::in);
    string line;
    infile >> line;    
    while ( !infile.eof() ) {
        if ( line[0] == 'A' ) { 
            Entry* e = get_entry( line );
            ht.insert( *e );
            delete e;
        }
        else {
            string key = get_key(line);
            if ( line[0] == 'D' ) {
                cout << "Removing " << key << "...\n";
                bool removed = ht.remove( key );
                if ( removed )
                    cout << key << " is removed successfully...\n\n";
                else
                    cout << key << " does not exist, no key is removed...\n\n";
            }
            else if ( line[0] == 'S' ) {
                int found = ht.search( key );
                if ( found < 0 ) 
                    cout << key << " does not exit in the hash table ..." << endl << endl;
                else
                   cout << key << " is found at table position " << found << endl << endl;
            }
            else if ( line[0] == 'P' ) {
                cout << "\nDisplaying the table: " << endl;
                ht.print();
            }
            else
                cerr << "wrong input: " << line << endl;
	}
        infile >> line;

    }

    infile.close();
    return 0;
}
