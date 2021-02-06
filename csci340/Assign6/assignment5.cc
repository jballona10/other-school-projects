#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "assignment5.h"
using namespace std;

const int MAX_SIZE = 40;
const int MAX_COUNT = 40;
const int WIDTH = 5;
const int ROW_SIZE = 8;

int mcount = 0;
int rcount = 0;


/************************
* Node constructor that
* sets left and right
* ptrs to null
***********************/
Node::Node()
{
	left = NULL;
	right = NULL;
	
}

/********************************
* binTree constructor sets root 
* to null
*********************************/
binTree::binTree()
{
	root = NULL;
}

/********************************
* binTree destructor deletes nodes
*******************************/
binTree::~binTree()
{
	delete root->left;
	delete root->right;
	delete root;
}

/*********************************************
* public height method calls private method
*********************************************/
int binTree::height() const
{
	return height(root);
} 

/********************************************
* public size method calls private size method
**********************************************/
unsigned binTree::size() const
{
	return size(root);
}

/**********************************************
* public insert method calls private insert 
* method
***********************************************/
void binTree::insert(int v) 
{
	insert(root,v);
}

/**********************************************
* public inorder method calls private inorder 
* method
***********************************************/
void binTree::inorder( void(*p)(int))
{
	inorder(root, *p);
}

/**********************************************
* public preorder method that calls private 
* preoder method
*********************************************/
void binTree::preorder(void (*p)(int))
{
	preorder(root, *p);
}

/***********************************************
* public postorder method that calls private 
* postorder method
*********************************************/
void binTree::postorder(void (*p)(int))
{
	postorder(root, *p);
}

/************************************************
* private height method that returns the height
* of the binary tree
* *********************************************/
int binTree::height(Node * node) const
{
	// if the node is empty, return -1
	if (node == NULL)
		return -1;
	else
	{
		int leftheight = height(node->left); // get the height of the left subtree
		int rightheight = height(node->right); // get the height of the right subtree
		if (leftheight > rightheight) // if left height is bigger than right height
			return (leftheight + 1);
		else // if right height is bigger than left height
			return (rightheight + 1); 
	}
	return 0;

}

/*************************************************
* private size method that returns the numer of nodes
***************************************************/
unsigned binTree::size(Node * subroot) const
{
	if (subroot == NULL) // if node is empty, return 0
		return 0;
	else // else return 1 plus the size of the right subtree and the size of the left subtree
		return 1 + size(subroot->right) + size(subroot->left);
}

/***************************************************
* private insert method that inserts a new node into 
* the tree
*****************************************************/
void binTree::insert(Node * & leaf, int v)
{
	// if the node is empty, add new node there
	if (leaf == NULL)
	{
		leaf = new Node;
		leaf->val = v;
	}
	else
	{
		// if the size of the left subtree is bigger
		// insert node into the left subtree
		if (size(leaf->right) < size(leaf->left))
		{
			insert(leaf->right, v);
		}
		else // insert into right subtree
			insert(leaf->left, v);
	}
}

/*****************************************************
* private inorder method that traverses the tree inorder
*****************************************************/
void binTree::inorder(Node * node, void (*p)(int))
{
	if (node != NULL)
	{
		inorder(node->left, *p);
		p(node->val);
		inorder(node->right, *p);
	}
}

/*************************************************
* private method that traverses the tree in preorder
***************************************************/
void binTree::preorder(Node * node, void (*p)(int))
{
	if (node != NULL)
	{
		p(node->val);
		preorder(node->left, *p);
		preorder(node->right, *p);
	}
}

/**************************************************
*  private method that traverses the tree in postorder
*************************************************/
void binTree::postorder(Node * node, void (*p)(int))
{
	if (node != NULL)
	{
		postorder(node->left, *p);
		postorder(node->right, *p);
		p(node->val);
	}
}

void display(int d) {
    if ( mcount < MAX_COUNT ) {
        cout << setw(WIDTH) << d;
        mcount++;
        rcount++;
        if ( rcount == ROW_SIZE ) {
            cout << endl;
            rcount = 0;
        }
    }
}

//#define BINTREE_MAIN
#ifdef BINTREE_MAIN
int main() {
    vector<int> v(MAX_SIZE);
    for (int i=1; i<MAX_SIZE; i++)
        v[i] = i;
    random_shuffle( v.begin(), v.end() );

    binTree bt;
    vector<int>::iterator it;
    for (it=v.begin(); it!=v.end(); it++)
	bt.insert( *it );

    cout << "Height: " << bt.height() << endl;
    cout << "Size: " << bt.size() << endl;
    cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.inorder( display );
    cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.preorder( display );
    cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.postorder( display );

    cout << endl;
    return 0;
}

#endif
