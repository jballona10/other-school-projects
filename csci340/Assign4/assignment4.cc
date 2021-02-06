/********************************************************
* Josue Ballona
* Assignment 4
* Feb 23
* CSCI340
* Z1832823
* Purpose: Practice implementing a Queue class using STL stacks
********************************************************/


#include <iostream>
#include <string>
#include <iomanip>
#include "assignment4.h"
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;

/*************************************
* empty const
* Parameters: none
* Returns: bool. True if both stacks inside
*		class are empty
* Purpose: Checks to see if the whole Queue
* 		is empty
*****************************************/
bool Queue::empty() const
{
	// set a bool to false
	bool tf = false;
	// if both stacks are empty change tf to true
	if (s1.empty() && s2.empty())
		tf = true;
	return tf;
}

/*******************************************
* size() const
* Paramters: none
* Returns: an int representing the number of
*	items in the Queue
* Purpose: finds number of ints in both stacks
********************************************/ 
int Queue::size() const
{
	// return sum of sizes of stacks
	return s1.size() + s2.size(); 
}

/************************************************
* front()
* Paramters: none
* Returns: an int representing the oldest element
* Purpose: Get the value of the oldest element in the queue
************************************************/
int Queue::front()
{
	// if the second stack is empty,
	if (s2.empty())
	{
		// move items from s1 to s2
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop(); // remove items from s1
		}
		return s2.top(); // return top most element
	}

	// else just return the top element of s2
	return s2.top();
}

/************************************************
* back()
* Parameters: none
* Returns an int representing the neweset element
* Purpose: get the value of the newest element
*************************************************/
int Queue::back()
{
	return s1.top(); // return newest element
}

/**********************************************
* push()
* Paramters: 1. val: reference to a const int
*		representing the number to put in 
*		queue
* Returns: void
* Purpose: add a new element into the queue
*********************************************/
void Queue::push(const int & val)
{
	s1.push(val); // add val to s1
}

/*********************************************
* pop()
* Parameters: none
* Returns: void
* Purpose: remove the oldest element
*********************************************/
void Queue::pop()
{
	// get oldest element into s2 and pop it
	this->front();
	s2.pop();
}

int main() {
    Queue q;
    string op;
    int val = 0;
 
   cout << "operation -- size front end" << endl;
   cin >> op;
   while ( !cin.eof() ) {
        if ( op == "push" ) {
            cin >> val;
            q.push( val );
            cout << op << " " << val << "    -- ";
        }
        else if ( op == "pop" ) {
            q.pop();
            cout << op << "       -- ";
        }
        else {
            cout << "Error input: " << op << endl;
            return 1;
        }
        cout << setw(3) << q.size() << setw(5) << q.front() << setw(5) << q.back() << endl;
        cin >> op;
    }

    while ( !q.empty() )
        q.pop();

    return 0;
}
