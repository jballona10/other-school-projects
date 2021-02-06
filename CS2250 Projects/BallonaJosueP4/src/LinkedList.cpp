#include "LinkedList.hpp"

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

void LinkedList::reAppend(int a)
{
	ListNode * newNode;
	newNode = new ListNode;
	newNode->data = a;


	// if empty list
	if (!head)
	{
		head = newNode;
		newNode->next = tail;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}

void LinkedList::appendNode(int b)
{
	// pointers for new node and to move through the list
	ListNode * newNode, * nodePtr;
	// allocate the new node
	newNode = new ListNode;
	newNode->data = b;
	newNode->next = nullptr;


	// if empty list
	if (!head)
	{
		head = newNode;
		newNode->next = tail;
	}
	else // insert node at the end
	{
		// initialize nodePtr to head
		nodePtr = head;

		// find the last node
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// insert newNode as the last node
		// make newNode point to tail
		nodePtr->next = newNode;
		newNode->next = tail;
	}
}

void LinkedList::insertNodeInSortedOrder(int c)
{
	// pointers for new node and to move through the list
	ListNode * newNode, * nodePtr;
	// dynamically allocate the new node
	newNode = new ListNode;
	newNode->data = c;
	newNode->next = nullptr;

	// initialize nodePtr to head
	nodePtr = head;
	// while the number in the nodes is smaller than c
	// make nodePtr point to the next node
	while (nodePtr->data > c)
		nodePtr = nodePtr->next;
	// set newNode next to the pointer after the one with c
	newNode->next = nodePtr->next;
	// set nodePtr next to new node
	nodePtr->next = newNode;
}

void LinkedList::deleteNodeOfValue(int d)
{
	// pointer to move through list
	ListNode * nodePtr, * previousPtr;

	// initialize nodePtr to head
	nodePtr = previousPtr = head;

	// if only one node
	if (ListNode::objectcount == 1)
	{
		if (nodePtr->data == d)
		{
			head = nullptr;
			delete nodePtr;
			ListNode::objectcount--;
		}
		else
		{
			cout << "The value does not exist in the list\n";
			return;
		}
	}
	else
	{
		// move through list to find the first instance of d
		while (nodePtr->data != d && nodePtr != nullptr)
		{
			previousPtr = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr->data == d)
		{
			previousPtr->next = nodePtr->next;
			delete nodePtr;
			ListNode::objectcount--;
			return;
		}
		else if (!nodePtr)
		{
			cout << d << " could not be found";
			return;
		}
	}
}

void LinkedList::deleteNodeAtLocation(int e)
{
	//  ptrs to move through the list
	ListNode * nodePtr, * previousPtr;

	//initialize nodePtr to head
	nodePtr = previousPtr = head;

	/*if (ListNode::objectcount == 1)
	{
		if (e > 1 || e < 1)
		{
			cout << "The location chosen does not exist\n";
		}

	}*/
	if (e > ListNode::objectcount)
	{
		cout << "The location chosen does not exist\n";
		return;
	}
	else
	{
		// move through list to find the location.
		for (int count = 1; count < e; count++)
		{
			previousPtr = nodePtr;
			nodePtr = nodePtr->next;
		}

		// delete node
		previousPtr->next = nodePtr->next;
		if (ListNode::objectcount == 1)
		{
			head = nullptr;
			delete nodePtr->next;
		}
		else
		{
			delete nodePtr;
		}
		ListNode::objectcount--;

	}
}

int LinkedList::getNodeValueAtLocation(int f)
{
	// pointer to move through list
	ListNode * nodePtr;

	//initialize nodePtr to head
	nodePtr = head;

	// if f is larger than objectcount
	if (f > ListNode::objectcount)
	{
		cout << "The location chosen does not exist\n";
		return 0;
	}
	else
	{
		for (int count = 1; count < f; count++)
		{
			nodePtr = nodePtr->next;
		}
		return nodePtr->data;
	}
}

void LinkedList::mergeTwoNodes(int g, int h)
{
	// pointers to find locations g, h, and the one before h
	ListNode * nodePtrg, * nodePtrh, * previousPtrh;

	// initialize nodePtrg and nodePtrh to head
	nodePtrg = nodePtrh = head;

	if (g > ListNode::objectcount || h > ListNode::objectcount)
	{
		cout << "One (or both) of the locations chosen does not exist\n";
	}
	else
	{
		// find the node at location g
		for (int count = 0; count < g; count++)
		{
			nodePtrg = nodePtrg->next;
		}
		// find node at location h and one previous
		for (int count = 0; count < h; count++)
		{
			previousPtrh = nodePtrh;
			nodePtrh = nodePtrh->next;
		}

		// add the values together and store them in location g
		nodePtrg->data = nodePtrg->data +nodePtrh->data;
		// make the previousPtrh point to the pointer after nodeptrh
		previousPtrh->next = nodePtrh->next;
		// delete nodeptrh
		delete nodePtrh;
	}
}

void LinkedList::swapNodes(int i, int j)
{
	// pointers to find locations i and j
	ListNode * nodePtri, * nodePtrj;
	// temp variable to hold one of the values
	int temp = 0;

	// initialize pointers to head
	nodePtri = nodePtrj = head;

	// if i or j is greater than number of nodes
	if (i > ListNode::objectcount || j > ListNode::objectcount)
	{
		cout << "One or both of the locations does not exist\n";
	}
	else
	{
		// find node at i
		for (int count = 0; count < i; count++)
		{
			nodePtri = nodePtri->next;
		}
		// find node at j
		for (int count = 0; count < j; count++)
		{
			nodePtrj = nodePtrj->next;
		}

		// store the value at i in temp
		temp = nodePtri->data;
		// store the value at j in nodePtri
		nodePtri->data = nodePtrj->data;
		// store temp in nodePtrj
		nodePtrj->data = temp;
	}
}

void LinkedList::removeAllDuplicates()
{
	// ptr to go through list
	ListNode * nodePtr, * previousPtr;
	// highest value in list
	int highestval = 0;

	//initialize nodePtr to head
	nodePtr = head;

	// find the highest value in the list
	while (nodePtr)
	{
		if (nodePtr->data > highestval)
			highestval = nodePtr->data;
		nodePtr = nodePtr->next;
	}

	// create an array of size highestval
	int arr[highestval+1];
	// count how many times each data variable appears
	nodePtr = head;
	while (nodePtr)
	{
		arr[nodePtr->data]++;
		nodePtr = nodePtr->next;
	}
	nodePtr = previousPtr = head;

	// move through list and see if there are any duplicates
	while (nodePtr)
	{
		if (arr[nodePtr->data] > 1)
		{
			previousPtr->next = nodePtr->next;
			delete nodePtr;
			nodePtr = previousPtr->next;
		}
		previousPtr= nodePtr;
		nodePtr = nodePtr->next;
	}
}

int LinkedList::numberOfNodes()
{
	return ListNode::objectcount;
}

void LinkedList::displayList() const
{
	// pointer to move through list
	ListNode * nodePtr;

	// initialize nodeptr to head
	nodePtr = head;

	while (nodePtr)
	{
		cout << nodePtr->data << " ";
		nodePtr = nodePtr->next;
	}
}

void LinkedList::deleteList()
{
	// pointers to move through and delete list
	ListNode * nodePtr, * previousPtr;

	// initialize nodePtr to head
	nodePtr = head;

	while (nodePtr)
	{
		previousPtr = nodePtr;
		nodePtr = nodePtr->next;
		delete previousPtr;
	}
}

int LinkedList::ListNode::objectcount = 0;
