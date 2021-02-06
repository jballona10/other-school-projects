#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::vector;

const int DATA_SIZE = 100;
const int SEARCH_SIZE = 50;
const int DATA_SEED = 11;
const int SEARCH_SEED = 7;
const int NO_ITEMS = 10;
const int ITEM_W = 6;

void genRndNums( vector<int>& v, int seed ) {
        srand(seed);

        for (int i = 0; i < v.max_size(); i++)
        {
                v[i] = rand();
        }
}

bool linearSearch( const vector<int>& inputVec, int x) {
}

bool binarySearch( const vector<int>& inputVec, int x) {
}

int search( const vector<int>& inputVec, const vector<int>& searchVec,
            bool (*p)( const vector<int>&, int) ){
}

void sortVector (vector<int>& inputVec) {
}

void printStat (int totalSucCnt, int vec_size) {
}

void print_vec( const vector<int>& vec ){
        cout << setw(ITEM_W);
        for (int i = 0; i < vec.size(); i++)
        {
                cout << vec[i] << " ";
        }
}

int main() {
    vector<int> inputVec(DATA_SIZE);
    vector<int> searchVec(SEARCH_SIZE);
    genRndNums(inputVec, DATA_SEED);
    genRndNums(searchVec, SEARCH_SEED);

 /*   cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
    print_vec( inputVec );
/*    cout << "----- " << searchVec.size() << " random numbers to be searched -------" << endl;
    print_vec( searchVec );

/*    cout << "\nConducting linear search on unsorted data source ..." << endl;
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
*/
    return 0;
}
