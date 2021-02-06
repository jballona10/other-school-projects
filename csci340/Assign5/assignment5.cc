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


Node::Node()
{
	left = NULL;
	right = NULL;
	
}

binTree::binTree()
{
	root = NULL;
}

int binTree::height() const
{
	height(root);
} 

unsigned binTree::size() const
{
	size(root);
}

void binTree::insert(int v) 
{
	insert(root,v);
}

void binTree::inorder( void(*p)(int))
{
	inorder(root, *p);
}

void binTree::preorder(void (*p)(int))
{
	preorder(root, *p);
}

void binTree::postorder(void (*p)(int))
{
	postorder(root, *p);
}

int binTree::height(Node * node) const
{
	if (node == NULL)
		return -1;
	else
	{
		int leftheight = height(node->left);
		int rightheight = height(node->right);
		if (leftheight > rightheight)
			return (leftheight + 1);
		else
			return (rightheight + 1);
	}


}

unsigned binTree::size(Node * subroot) const
{
	if (subroot == NULL)
		return 0;
	else
		return 1 + size(subroot->right) + size(subroot->left);
}

void binTree::insert(Node * & leaf, int v)
{
	if (leaf == NULL)
	{
		leaf = new Node;
		leaf->val = v;
	}
	else
	{
		if (size(leaf->right) < size(leaf->left))
		{
			insert(leaf->right, v);
		}
		else
			insert(leaf->left, v);
	}
}

void binTree::inorder(Node * node, void (*p)(int))
{
	if (node != NULL)
	{
		inorder(node->left, *p);
		p(node->val);
		inorder(node->right, *p);
	}
}

void binTree::preorder(Node * node, void (*p)(int))
{
	if (node != NULL)
	{
		p(node->val);
		preorder(node->left, *p);
		preorder(node->right, *p);
	}
}

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

#define BINTREE_MAIN
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
