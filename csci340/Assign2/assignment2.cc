/**************************************************
* Josue Ballona
* Z1832823
* CSCI340 
* Section 2
* Assignment 2
* 7 Feb 2018
*
* Purpose: implement two search algorithms from the <algorithm> 
		library
***************************************************/

#include <iostream>
#include <vector>
#include <cstdlib> // setw
#include <iomanip> // setprecision
#include <algorithm>

using std::cout;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::vector;

const int DATA_SIZE = 100;
const int SEARCH_SIZE = 50;
const int DATA_SEED = 11;
const int SEARCH_SEED = 7;
const int NO_ITEMS = 10;
const int ITEM_W = 6; 
const int LOW = 1;
const int HIGH = 100;

/****************************************
* genRndNums
* Parameters: 2.
*	1. &v: reference to a vector to fill 
*	2. seed: int to seed srand with
* Returns: void
* Purpose: fills a vector with random numbers
*****************************************/
void genRndNums( vector<int>& v, int seed ) {
	srand(seed); // seed RNG
	// for loop to fill vector
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
		*i = rand() % (HIGH - LOW + 1) + LOW;
}

/*******************************
* linearSearch
* Parameters: 2
*	1. inputVec: reference to a const vector 
*		filled with random numbers
*	2. x: int to be searched for in the vector
* Returns: bool: true if x was found
*
* Purpose: searches for x in the vector and returns
*	true or false
***************************************/
bool linearSearch( const vector<int>& inputVec, int x) {
	vector<int>::const_iterator it; // iterator declaration
	// find x in inputVec and set the iterator to its location
	it = find(inputVec.begin(), inputVec.end(), x);
	
	// if it = end of inputVec, x was not found
	if (it == inputVec.end())
		return false;
	return true; 
}

/*******************************************************
* binarySearch
* Parameters: 2;
*	1. inputVec: reference to a const vector filled
*		with random ints
*	2. x: int to search for
* Returns: bool. True if x is found
*
* Purpose: find x in inputVec through a binary search
********************************************************/
bool binarySearch( const vector<int>& inputVec, int x) {
	// returns true if x is found inputVec
	return binary_search(inputVec.begin(), inputVec.end(), x);
}

/********************************************************************
* search
* Parameters: 3;
*	1. inputVec: reference to const vector filled with rand ints
*	2. searchVec: reference to const vector filled with ints to 
*		be searched
*	3. (*p): pointer to a function pointing to one of the search
*		functions
* Returns: an int representing the number of successful searches
********************************************************************/ 
int search( const vector<int>& inputVec, const vector<int>& searchVec,
            bool (*p)( const vector<int>&, int) ){
	int count = 0;
	for (vector<int>::const_iterator i = searchVec.begin(); i != searchVec.end(); i++)
	{
		if(p(inputVec, *i) == true)
			count++;
	}
	return count;
}

/***************************************
* sortVector
* Parameters: 1;
*	1. inputVec: reference to a vector to sort
* Returns: void
* 
* Purpose: sorts vector using sort algorithm
******************************************/
void sortVector (vector<int>& inputVec) {
	// sort function from <algorithm> lib used
	sort(inputVec.begin(), inputVec.end());
}


/************************************************
* printStat
* Parameters: 2;
*	1. totalSucCnt: int representing successful search count
*	2. vec_size: int representing the vector size
* Returns: void
* 
* Purpose: print out the percentage of successful searches
*************************************************/
void printStat (int totalSucCnt, int vec_size) {
	// print out percentage of successful searches
	// two decimal places
	cout << "Successful searches: ";
	cout << setprecision(2) << fixed << (double)totalSucCnt / vec_size * 100;
	cout << "%\n";
}

/****************************************
* print_vec
* Parameters: 1;
*	1. vec: reference to a const vector to print
* Returns: void
* 
* Purpose: output the vector to the screen
******************************************/
void print_vec( const vector<int>& vec ){
	int count = 0; // set a counter to 0

	// for loop to print out the vector elements
	for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); i++)
	{
		// print ten items per line
		if (count == NO_ITEMS)
		{
			count = 0;
			cout << endl;
		}
		// allocate 6 spaces for each item
		cout << setw(ITEM_W) << *i << " ";
		count++;
	}
	cout << endl; // print new line at the end
}

int main() {
    vector<int> inputVec(DATA_SIZE);
    vector<int> searchVec(SEARCH_SIZE);
    genRndNums(inputVec, DATA_SEED);
    genRndNums(searchVec, SEARCH_SEED);

    cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
    print_vec( inputVec );
    cout << "----- " << searchVec.size() << " random numbers to be searched -------" << endl;
    print_vec( searchVec );

    cout << "\nConducting linear search on unsorted data source ..." << endl;
    int linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on unsorted data source ..." << endl;
    int binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    sortVector( inputVec );

    cout << "\nConducting linear search on sorted data source ..." << endl;
    linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on sorted data source ..." << endl;
    binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    return 0;
}

