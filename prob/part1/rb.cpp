#include "rb.h"
#include<iostream>
using namespace std;
using ptr = RedBlackTree::ptr;

RedBlackTree::RedBlackTree(){}

const ptr RedBlackTree::getRoot() const
{ 
	return root; 
}

ptr RedBlackTree::insert(int data)
{
	ptr newnodePtr = new node(data);
	if (!root) {
		root = newnodePtr;
		root->color = 0; // set root color as black
		return newnodePtr;
	}
	insert(root, newnodePtr);
	return newnodePtr;
}

// auxiliary function to perform RBT insertion of a node
// you may assume start is not nullptr
void RedBlackTree::insert(ptr start, ptr newnodePtr)
{
	// choose direction
	ptr x = getRoot();
	ptr y = nullptr;
	while (x != nullptr) {
		y = x;
		if (x->data > newnodePtr->data) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	if (y == nullptr) {
		root = newnodePtr;
	}
	if (y->data > newnodePtr->data) {
		y->left = newnodePtr;
	}
	else {
		y->right = newnodePtr;
	}
	newnodePtr->parent = y;
	// recurse down the tree
	return;
}

// Credits to Adrian Schneider
void RedBlackTree::printRBT(ptr start, const std::string& prefix, bool isLeftChild) const
{
	if (!start) return;

	std::cout << prefix;
	std::cout << (isLeftChild ? "|--" : "|__" );
	// print the value of the node
	std::cout << start->data << "(" << start->color << ")" << std::endl;
	// enter the next tree level - left and right branch
	printRBT(start->left, prefix + (isLeftChild ? "│   " : "    "), true);
	printRBT(start->right, prefix + (isLeftChild ? "│   " : "    "), false);
}

// Function performing right rotation
// of the passed node
void RedBlackTree::rightrotate(ptr loc)
{	
	if (loc == root) return;
	ptr T1 = loc->left;
	ptr T2 = loc->right;
	ptr parent_loc = loc->parent;
	ptr T3 = parent_loc->right;
	ptr grandparent = parent_loc->parent;
	if (grandparent == nullptr) {
		root = loc;
	}
	else {
		if (grandparent->right == parent_loc) {
			grandparent->right = loc;
			loc->parent = grandparent;
		}
		else {
			grandparent->left = loc;
			loc->parent = grandparent;
		}
	}
	parent_loc->left = T2;
	T2->parent = parent_loc;
	loc->right = parent_loc;
	parent_loc->parent = loc;
}

// Function performing left rotation
// of the passed node
void RedBlackTree::leftrotate(ptr loc)
{
	if (loc == root) return;
	ptr parent_loc = loc->parent;
	ptr T1 = parent_loc->left;
	ptr T2 = loc->left;
	ptr T3 = loc->right;
	ptr grandparent = parent_loc->parent;
	if (grandparent == nullptr) {
		root = loc;
	}
	else {
		if (grandparent->right == parent_loc) {
			grandparent->right = loc;
			loc->parent = grandparent;
		}
		else {
			grandparent->left = loc;
			loc->parent = grandparent;
		}
	}
	parent_loc->right = T2;
	T2->parent = parent_loc;
	loc->left = parent_loc;
	parent_loc->parent = loc;
}

// This function fixes violations
// caused by RBT insertion
void RedBlackTree::fixup(ptr loc)
{	
	if (loc == root) {
		loc->color = 0;
		return;
	}
	// cout<<"HELLO";
	ptr parent_loc = loc ->parent;
	
	// cout<<parent_loc->color<<endl;
	// if (parent_loc == root) {
	// 	return;
	// }
	
	ptr grandparent = parent_loc ->parent;
	if (grandparent == nullptr) return;
	// cout<<grandparent->data;
	ptr uncle;
	// cout<<"HELLO"<<endl;
	// cout<<grandparent->right<<endl;
	// cout<<parent_loc<<endl;
	if (grandparent->right != nullptr && grandparent -> right == parent_loc) {
		// cout<<"HELLO"<<endl;
		uncle = grandparent->left;
		// cout<<"HELLO"<<endl;
	}
	else {
		// cout<<"HELLO3";
		uncle = grandparent->right;
	}
	// cout<<"HELLO"<<endl;
	if (uncle != nullptr) {
		if (uncle->color == 1) {
			uncle->color = 0;
			parent_loc->color = 0;
			grandparent->color = 1;
			if (grandparent == root) {
				grandparent->color = 0;
				return;
			}
			if (grandparent->parent->color == 0) return;
			else {
				return fixup(grandparent);
			}
		}
	}
	// cout<<"HELLO"<<endl;
	if (grandparent->right->left == loc) {
		rightrotate(loc);
	}
	if (grandparent->left->right == loc) {
		leftrotate(loc);
	}
	if (grandparent->right->right == loc) {
		// cout<<"HELLO"<<endl;
		leftrotate(parent_loc);
		grandparent->color = 1;
		parent_loc->color = 0;
	}
	if (grandparent->left->left == loc) {
		rightrotate(parent_loc);
		grandparent->color = 1;
		parent_loc->color = 0;
	}
}

// Function to print inorder traversal
// of the fixated tree
void RedBlackTree::inorder(ptr start) const
{
	if (!start)
		return;
	
	inorder(start->left);
	std::cout << start->data << " ";
	inorder(start->right);
}

// driver code
int main()
{
	int n; std :: cin >> n;
	assert (n < 10000 && n >= 0);
	int a[10000];
	RedBlackTree tree;

	for (int i = 0; i < n; i++) {
		std::cin >> a[i];

		// allocating memory to the node and initializing:
		// 1. color as red
		// 2. parent, left and right pointers as NULL
		// 3. data as i-th value in the array

		// calling function that performs rbt insertion of
		// this newly created node
		auto newnodePtr = tree.insert(a[i]);

		// calling function to preserve properties of rb
		// tree
		tree.fixup(newnodePtr);
	}
	tree.printRBT(tree.getRoot());

	return 0;
}
