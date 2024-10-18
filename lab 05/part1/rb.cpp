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
	//cout<<2<<endl;
	ptr newnodePtr = new node(data);
	if (!root) {
		root = newnodePtr;
		root->color = 0; // set root color as black
		return newnodePtr;
	}
	//cout<<2<<endl;
	insert(root, newnodePtr);
	return newnodePtr;
}

// auxiliary function to perform RBT insertion of a node
// you may assume start is not nullptr
void RedBlackTree::insert(ptr start, ptr newnodePtr)
{	
	//cout<<2<<endl;
	// choose direction
	ptr x = start;
	ptr y = nullptr;
	while(x != nullptr) {
		y = x;
		if (x->data > newnodePtr->data) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}

	if (y->data > newnodePtr->data) {
		y->left = newnodePtr;
	}
	else {
		y->right = newnodePtr;
	}
	newnodePtr->parent = y;
	// if (y->color == 1) {
	// 	fixup(newnodePtr);
	// }
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
	node* left = loc->left;
	node* right = loc->right;
	node* parent_right = nullptr;
	if (loc->parent != nullptr) {
		parent_right = loc->parent->right;
	}
	node* parent_loc = loc->parent;
	node* grandparent = nullptr;
	if(parent_loc != nullptr) {
		grandparent = parent_loc->parent;
	}
	if (grandparent != nullptr) {
		if (grandparent->left == parent_loc) {
			grandparent->left = loc;
			loc->parent = grandparent;
		}
		else {
			//cout<<"right"<<endl;
			grandparent->right = loc;
			loc->parent = grandparent;
		}
	}
	if (parent_loc != nullptr) {
		loc->right = parent_loc;
		parent_loc->left = right;
		parent_loc->parent = loc;
		//cout<<"right"<<endl;
		if (grandparent == nullptr) {
			root = loc;
		}
		//cout<<"right"<<endl;
	}
	if (left != nullptr) {
		left->parent = parent_loc;}
	//fixup(loc);
	loc->parent = grandparent;
	//cout<<"right"<<endl;
}

// Function performing left rotation
// of the passed node
void RedBlackTree::leftrotate(ptr loc)
{	
	//cout<<loc->data;
	node* left = loc->left;
	node* right = loc->right;
	node* parent_left = nullptr;
	if (loc->parent != nullptr) {
		//cout<<"right"<<endl;
		parent_left = loc->parent->left;
		
	}
	node* parent_loc = loc->parent;
	node* grandparent = nullptr;
	if(parent_loc != nullptr) {
		//cout<<"right"<<endl;
		//cout<<parent_loc->data;
		grandparent = parent_loc->parent;
		// if (grandparent != nullptr) {
		// 	cout<<"right"<<endl;
			
		// }
	}
	if (grandparent != nullptr) {
		if (grandparent->left == parent_loc) {
			grandparent->left = loc;
			loc->parent = grandparent;
		}
		else {
			//cout<<"insideleftrotate"<<endl;
			grandparent->right = loc;
			loc->parent = grandparent;
		}
	}
	//else cout<<"wrong"<<endl;
	if (parent_loc != nullptr) {
		//cout<<"insideif"<<endl;
		loc->left = parent_loc;
		parent_loc->right = left;
		parent_loc->parent = loc;
		if (grandparent == nullptr) {
			root = loc;
		}
		
	}
	if (left != nullptr) {
		left->parent = parent_loc;}
	
	loc->parent = grandparent;
	//fixup(loc);
}

// This function fixes violations
// caused by RBT insertion
void RedBlackTree::fixup(ptr loc)
{	
	//cout<<loc->data<<endl;
	if (loc->parent == nullptr) {
		loc->color = 0;
		return;
	}
	node* parent_loc = loc->parent;
	node* sibling = nullptr;
	node* grandparent = nullptr;
	if (parent_loc != nullptr) {
		grandparent = parent_loc->parent;
	}
	//cout<<2<<endl;
	if (grandparent != nullptr) {
		if (grandparent->right == parent_loc) {
			sibling = grandparent->left;
		}
		else {
			sibling = grandparent->right;
		}
	}
	//cout<<10<<endl;
	if (sibling != nullptr && sibling->color == 1) {
		//cout<<"Entered here"<<endl;
		grandparent->color = 1;
		sibling->color = 0;
		parent_loc->color = 0;
		//cout<<grandparent->data<<endl<<parent_loc->data<<endl;
		if (grandparent->parent != nullptr) {
			if (grandparent->parent->color == 0) {
				//cout<<"ENTERED"<<endl;
				return;
			}
			else {
				//cout<<"Entered here"<<endl;
				// grandparent->color = 1;
				// parent_loc->color = 0;
				// sibling->color = 0;
				fixup(grandparent);
				return;
			}
		}
		else {
			grandparent->color = 0;
			return;
		}
	}
	//cout<<10<<endl;
	if (grandparent != nullptr) {
		if (grandparent->right!= nullptr) {
			if (grandparent->right->left == loc) {
				rightrotate(loc); 
				ptr temp = parent_loc;
				parent_loc = loc;
				loc = temp;
				//cout<<"right"<<endl;
			}
		}
	}
	//cout<<10<<endl;
	if (grandparent != nullptr) {
		if (grandparent->left!= nullptr) {
			if (grandparent->left->right == loc) {
				rightrotate(loc);
				ptr temp = parent_loc;
				parent_loc = loc;
				loc = temp;}
		}
	}
	//cout<<10<<endl;
	if (grandparent != nullptr) {
		if (grandparent->left!= nullptr) {
			if (grandparent->left->left == loc) {
				rightrotate(parent_loc);
			parent_loc->color = 0;
			grandparent->color = 1;
			return;}
		}
	}
	//cout<<10<<endl;
	if (grandparent != nullptr) {
		if (grandparent->right!= nullptr) {
			if (grandparent->right->right == loc) {
				//cout<<"inside"<<endl;
				leftrotate(parent_loc);
				//cout<<"leftrotatedone";
				parent_loc->color = 0;
				grandparent->color = 1;
				return;}
		}
	}
	if (grandparent != nullptr && grandparent->left->right == loc) {
		leftrotate(loc);
	}
	if (grandparent != nullptr && grandparent->right->right == loc) {
		leftrotate(parent_loc);
		parent_loc->color = 0;
		grandparent->color = 1;
		return;
	}
	
	if (grandparent != nullptr && grandparent->left->left == loc) {
		rightrotate(parent_loc);
		parent_loc->color = 0;
		grandparent->color = 1;
		return;
	}
	if (grandparent == nullptr) {
		parent_loc->color = 0;
	}
	//cout<<10<<endl;
	// if (grandparent == nullptr) {
	// 	return;
	// }
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