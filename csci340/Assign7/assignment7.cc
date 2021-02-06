/*******************************************
* Josue Ballona
* CSCI340 Section 2
* Z1832823
* Assignment 7: Due April 6
* Purpose: Implement functions that work with
* an array using the heapsort techniques. 
* First building a heap structure than 
* sorts them and prints them out
**********************************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::setw;


const int HEAP_SIZE = 50;


void build_heap(vector<int> &, int, bool(*)(int, int));

void heapify(vector<int> &, int, int, bool(*)(int, int));

bool less_than(int, int);

bool greater_than(int, int);

void heap_sort(vector<int> &, int, bool(*)(int, int));

int extract_heap(vector<int> &, int &, bool(*)(int, int));

void print_vector(vector<int> &, int, int);

/*********************************************************************
* build_head
* returns nothing, but constructs heap with heap_size elements in vector
* Takes a vector, an int represeting heap size, and a ptr to a function 
* that returns bool representing a greater than or less than function
************************************************************************/
void build_heap(vector<int> & v, int heap_size, bool (*compar)(int, int))
{
	for (int i = heap_size; i > 0; i--)
		heapify(v, heap_size, i, *compar);
}

/********************************************************************
* heapify
* returns nothing but heapifies a tree at position r.
* takes a vector, an int representing heap size, an int represnting 
* the root position, and a function to a ptr returning bool representing
* a greater than or less than function
***********************************************************************/
void heapify(vector<int> & v, int heap_size, int r, bool (*compar)(int, int))
{
	int left , right, heap;

	left = 2 * r ; // set left child of root
	right = ( 2 * r) + 1; // set right child of root
	heap = r; // set the largest element equal to r

	// if the left child pos is less than or equal to heapsize
	// and the element in the left child position is greater/less than
	// the element in the root position
	if (left <= heap_size && compar(v[left], v[r]))
		heap = left; // largest is at pos left

	// if right child pos is less than or equal to heapsize
	// and element in left child pos is greater/less than
	// element in root pos
	if (right <= heap_size && compar(v[right], v[heap]))
		heap = right; // largest is at pos right
	
	// if largest element not at root
	if (heap != r)
	{
		std::swap(v[r], v[heap]); // swap
	
		heapify(v, heap_size, heap, *compar); // create heap
	}
}


/**************************************************
* less_than 
* returns true if e1 is less than e2.
* Takes two integers representing numbers in the heap
*****************************************************/
bool less_than(int e1, int e2)
{
	if (e1 < e2)
		return true;
	return false;
}

/*****************************************************
* greater_than
* returns true if e1 is greater than e2
* Takes two integers representing numbers in the heap
*****************************************************/
bool greater_than(int e1, int e2)
{
	if (e1 > e2)
		return true;
	return false;
}

/*********************************************************
* heap_sort
* sorts the heap in desc or asc order depending on the 
* function pointer.
* takes a vector, an int representing the heap size,
* and the ptr to a function that returns a bool
********************************************************/
void heap_sort(vector<int> & v, int heap_size, bool (*compar)(int, int))
{
	build_heap(v, heap_size, *compar);
	for (int i = heap_size; i >= 2; i--)
	{
		v[i] = extract_heap(v, heap_size, *compar);
	}
	
	std::reverse(v.begin() + 1, v.end()); // flips order of vector elements starting at pos 1
}

/****************************************************
* extract_heap
* returns an int representing the old root value.
* extracts the root of the heap and fills it with 
* last element of current heap.
* Takes a vector, an int representing heap size,
* and a pointer to a function that returns a bool
*********************************************************/
int extract_heap(vector<int> & v, int & heap_size, bool (*compar)(int, int))
{

	int temp = v[1];
	v[1] = v[heap_size];
	heap_size--;

	heapify(v, heap_size, 1, *compar);
	return temp;
}
/*************************************************
* print_vector
* prints out the heap 8 elements per line each item 
* occupying 5 spaces
****************************************************/
void print_vector(vector<int> & v, int pos, int size)
{
	for (int i = pos; i <= size; i++)
	{
		cout << setw(5) << v[i] << " ";
		if (i % 8 == 0)
			cout << endl;
	}

	
	cout << endl;
}

int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake
    for (int i=1; i<=HEAP_SIZE; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+HEAP_SIZE+1 );

    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, HEAP_SIZE, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, HEAP_SIZE, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    return 0;
}
