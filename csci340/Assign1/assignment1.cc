/***************************************************
* Josue Ballona
* Z1832823
* Assignment 1
* CSCI 340
* Section 2
* Due: January 29
*
* Purpose: Implement search algorithms with vectors
****************************************************/
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>

using std::vector;
using std::cout;
using std::endl;
using std::setw;

const int DATA_SIZE = 200;
const int DATA_RANGE = 200;
const int DATA_SEED = 9;
const int SEARCH_SEED = 17;
const int NO_ITEMS = 8;
const int ITEM_W = 4;

int linear_search(const vector<int>& inputVec, const int x, int& comparisons) {
	// create a counter, i and set comparisons and i to 0
	int i = comparisons = 0;
	
	// while loop to loop as long as number has not been found and
	// end of loop has not been reached
	while (inputVec[i] != x && i < inputVec.size())
	{
		// increment i and comparisons by 1
		i++;
		comparisons++;
	}

	// if value found 
	if (inputVec[i] == x)
	{
		comparisons++;
		// return position
		return i;
	}
	
	// return -1 if false
	return -1;
}

int binary_search(const vector<int>& inputVec, const int x, int& comparisons) {
	
	// create begin and set it and comparisons to 0
	int begin = 0;
	comparisons = 0;
	// create end and set to end of vector
	int end = inputVec.size() - 1;
	// calculate middle of vector
	int middle = begin + (end - begin) / 2;

	// while beginning counter has not passed end counter
	while (begin <= end)
	{	
		// set new middle
		middle = begin + (end - begin) / 2;
		
		// if middle value is wanted value
		if (inputVec[middle] == x)
		{
			// increment comparisons and return position
			comparisons++;
			return middle;
		}

		// if value is greater than wanted value
		if (inputVec[middle] > x)
		{
			// calculate new end and increment
			end = middle - 1;
			comparisons++;
		}

		// if value is less than wanted value
		if (inputVec[middle] < x)
		{
			// calculate new beginning and increment
			begin = middle + 1;
			comparisons++;
		}
	}
	
	// return -1 if value not found
	return -1;
}

void print_vec( const vector<int>& vec ){
	// set a counter to 0
	int count = 0;

	// as long as i is less than vector size, keep loop going
	for (int i = 0; i < vec.size(); i++)
	{
		// if count is equal to NO_ITEMS (8)
		if (count == NO_ITEMS)
		{
			// create new line and restart count
			cout << endl;
			count = 0;
		}

		//output the data in the vector separated by space
		cout << setw(ITEM_W) << vec[i] << " ";
		// increment count
		count++;
	}
}
	
void average_comparisons(const vector<int>& inputVec, const vector<int>& searchVec, int (*search)(const vector<int>&, const int, int&) ) {
    int i, comparison = 0, sum = 0, found = 0;
    int res = 0;
    for (i = 0; i < (int)searchVec.size(); i++) {
        res = search( inputVec, searchVec[i], comparison );
        sum += comparison;
        if ( res >= 0 )
           found++;
    }
    cout << found << " numbers are found. The average number of comparisons in each search: " << (double)sum/(double)searchVec.size() << endl << endl;
}

int random_number() {
    return rand()%DATA_RANGE + 1;
}


int main () {

    // -------- create unique random numbers ------------------//
    vector<int> inputVec(DATA_SIZE);
    srand(DATA_SEED);
    generate(inputVec.begin(), inputVec.end(), random_number);
    sort(inputVec.begin(), inputVec.end());
    vector<int>::iterator it = unique(inputVec.begin(), inputVec.end());
    inputVec.resize( it - inputVec.begin() );
    random_shuffle( inputVec.begin(), inputVec.end() );

    cout << "------ Data source: " << inputVec.size() << " unique random numbers ------" << endl;
    print_vec(inputVec);
    cout << endl;

    // -------- create random numbers to be searched ---------//
    vector<int> searchVec(DATA_SIZE/2);
    srand(SEARCH_SEED);
    generate(searchVec.begin(), searchVec.end(), random_number);

    cout << "------ " << searchVec.size() << " random numbers to be searched: ------" << endl;
    print_vec(searchVec);
    cout << endl;

    cout << "Linear search: ";
    average_comparisons(inputVec, searchVec, linear_search);
    cout << "Binary search: ";
    average_comparisons(inputVec, searchVec, binary_search);

    sort(inputVec.begin(), inputVec.end());
    cout << "------- numbers in data source are now sorted ---------" << endl << endl;
    cout << "Linear search: ";
    average_comparisons(inputVec, searchVec, linear_search);
    cout << "Binary search: ";
    average_comparisons(inputVec, searchVec, binary_search);

    return 0;

}

