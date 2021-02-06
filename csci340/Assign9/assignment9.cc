#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "assignment9.h"
using namespace std;


int * num; // global pointer to int
string s; // global string









#define ASSIGNMENT9_TEST
#ifdef 	ASSIGNMENT9_TEST

/************************************
* graph
* Constructor that sets size and constructs
* graph from input file
* Parameters: 1) filename: ptr to a 
*		const char representing
*		filename
* Returns: nothing
*******************************************/
graph::graph(const char * filename)
{
	ifstream f(filename);
	if(!f.is_open()) {
		cerr << "filename invalid" << endl; exit(0); }

	f >> size; // set size before starting
	char temp[100];
	f.getline(temp, 1);
	f.getline(temp,100);
	{
		string line(temp);
		string::iterator end = remove_if(line.begin(), line.end(), static_cast<int(*)(int)>(isspace));
		line.erase(end, line.end());
		for (int i = 0; i < (int)line.size(); i++)
		labels.push_back('A' + i);
	}

	while (f)
	{
		list<int> val;
		f.getline(temp, 100);
		string line(temp);
		if(line.size() == 0)
			break;
		line.erase(remove_if(line.begin(), line.end(), static_cast<int(*)(int)>(isspace)), line.end());
		for (int i = 1; i < (int)line.size(); i++)
		{
			if(line[i] == '1')
				val.push_back(i-1);
		}
		adj_list.push_back(val);
	}
}

/********************
* ~graph
* destructor that deletes num
* if not deleted before
***********************/
graph::~graph()
{
	delete num;
}

/***********************************************************
* get_size const
* Fetches size of graph
* returns an integer
************************************************************/
int graph::get_size() const
{
	return size;
}

/********************************************************
* traverse
* function that traverses through the graph, calling 
* depth_first when necessary
* Returns: nothing
*********************************************************/
void graph::traverse()
{
	s = "";
	cout << "\n-------------Traversal------------" << endl;
	num = new int[size];
	/* set all spaces to 0 in num */
	for (int i = 0; i < size; i++)
		num[i] = 0;
	for (int i = 0; i < size; i++)
	{
		if (num[i] == 0)
			depth_first(i);
	}
	cout << endl << s << endl;

	delete num;
	cout << "---------------End of Traversal---------------" << endl;
}

/******************************************
* depth_first
* traverses graph in depth first search method
* Parameter: 1) v: representing starting vertex
* Returns nothing
*****************************************/
void graph::depth_first(int v)
{
	num[v]++;
	cout << labels[v] << " ";
	for (int i :adj_list[v])
	{
		if (num[i] == 0)
		{
			s = s +'(' + labels[v] + ',' + labels[i] + ')';
			depth_first(i);
		}
	}
}

/*********************************
* print const
* function prints out the graph 
* Returns nothing
********************************/
void graph::print() const
{
	int i = 0;
	cout << "Number of vertices in graph: " << size << endl;
	cout << "\n----------Graph----------" << endl;
	for (list<int> l: adj_list)
	{
		cout << (char)('A' + i++) << ": ";
		for (int c: l)
			cout << labels[c] << ",";
		cout << endl;
	}
	cout << "----------END----------" << endl;
}
int main(int argc, char** argv) {
    if ( argc < 2 ) {
        cerr << "args: input-file-name\n";
        return 1;
    }
    
    graph g(argv[1]);

    g.print();
    
    g.traverse();

    return 0;
}

#endif
