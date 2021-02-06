#include <iostream>
#include "assignment5.h"
#include "assignment6.h"
using namespace std;


/*************************************
* method to decide if a node is a leaf
**************************************/
bool BST::isLeaf(Node * node)
{
	if (node == NULL) // if node is empty return false
		return false;
	if (node->left == NULL && node->right == NULL) // else if right and left pts null return true
		return true;
	return false;
}

/*********************************
* public method that calls private 
* insert method
**********************************/
void BST::insert(int x) 
{
	insert(root, x);
}

/***********************************
* public search method that calls
* private search method
*************************************/
bool BST::search(int x)
{
	return search(root, x);
}

/**********************************
* public remove method that calls
* private remove method
***********************************/
bool BST::remove(int x)
{
	return remove(root, x);
}

/*************************************
* public sumleftleaves method that calls
* private sumleftleaves method
*************************************/
int BST::sumLeftLeaves()
{
	return sumLeftLeaves(root);
}

/***************************************
* private insert method that inserts 
* into tree keeping it a binary search tree
******************************************/
void BST::insert(Node * & node, int x)
{
	if (node == NULL) // if node is empty, insert there
	{
		node = new Node;
		node->val = x;
	}
	else // else keep traversing tree
	{
		if (x > node->val) // if x is greater than the data in current node
			insert(node->right, x); // insert it in right subtree
		else // if x is less than data in current node
			insert(node->left, x); //insert it in left subtree
	}
}

/***********************************************
* private search method that searches for a value
*************************************************/
bool BST::search(Node * & node, int x)
{
	if (node == NULL) // if node is empty return false
		return false;
	else if (node->val == x) //if node has the value wanted, return true
		return true;
	else if (node->val < x) // if node value is less than value wanted, search right subtree
		return search(node->right, x);
	else // search left subtree
		return search(node->left, x);
	return false;
}

/***************************************************
* private remove method that removes a node keeping
* it a binary search tree
***************************************************/
bool BST::remove(Node * & node, int x)
{
	Node * temp = NULL; // temp node to help

	if (node == NULL) // if node is empty return false
		return false;
	else if (node->val > x) //if node value is greater than wanted value, search left subtree
		return remove(node->left, x);
	else if (node->val < x) // if node value is less than wanted value, search right subtree
		return remove(node->right, x);
	else 
	{
		if (node->left != NULL && node->right != NULL) // if node has two children
		{
			temp = node->left; 
			while (temp->right != NULL) // search for immediate predecessor
				temp = temp->right;
			node->val = temp->val;
			return remove(node->left, temp->val); // remove 
		}
		else if (node->left == NULL && node->right == NULL) //if node is leaf delete
		{
			delete node;
			node = NULL;
			return true;
		}
		else // node has one child
		{
			temp = node;
			if (node->left == NULL)
				node = node->right;
			else
				node = node->left;
			delete temp;
			return true;
		}
	}
	return false;

}
 /*********************************************
* private method that sums the values in the left
* leaves only
*********************************************/
int BST::sumLeftLeaves(Node * & n)
{	int s = 0; // sum value
	if (n != NULL)
	{
		if (isLeaf(n->left)) // if node is aleaf,
			s += n->left->val; // add it to s
		else  // else keep searching 
			s += sumLeftLeaves(n->left);
		s += sumLeftLeaves(n->right);
	}
	return s;
}



