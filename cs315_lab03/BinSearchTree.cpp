/*
  Author: Adrian Smith
  Course: CS 315
  Assignment: Lab 03 Part B
*/
#include "BinSearchTree.hpp"
#include "TreeNode.hpp"

#include <iostream>

TreeNode *BinSearchTree::local_insert( TreeNode *root, int v ) {
   if( root == nullptr )
       return new TreeNode( v );
   if( root->value() < v )
       root->rightSubtree( local_insert( root->rightSubtree(), v ) );
   else
       root->leftSubtree( local_insert( root->leftSubtree(), v ) );
   return root;
}

void BinSearchTree::insert(int v) {
    if( ! find(v) )
        root = local_insert( root, v );                                                        
}

// Finds a key v within the BST named root.
// Relies on helper function for actual search
bool BinSearchTree::find( int v ){
	return recFind(root, v);
}

// Recursively searches a tree for a key and returns
// whether or not the key exists in the list
bool BinSearchTree::recFind( TreeNode *root, int key ) {
	// We have checked a subtree which doesn't exist
	if (root == nullptr) {
		return false;
	}
	
	// We have found our value
	if (root->value() == key){
		return true;
	}
	
	// Does the value exist in the left or right subtrees?
	if (key < root->value()) {
		return recFind(root->leftSubtree(), key);
	} else {
		return recFind(root->rightSubtree(), key);
	}
}

// Finds v in the binary tree at root
bool BinSearchTree::iterFind( int v ) {
	TreeNode *temp = root;
	
	// Dive into the tree until we reach the bottom
	while ( temp != nullptr ) {
		// If the node we are looking at has the value we are looking for
		if((temp->value()) == v) {
			return true;
		}

		// Is out value bigger or smaller than the node we are looking at
		if(v < (temp->value()))
		{
			// Look at the values smaller than the current one
			temp = temp->leftSubtree();
		} else {
			// Look at the values bigger than the current one
			temp = temp->rightSubtree();
		}
	}
	
	return false;
}

// Gets the number of nodes in a binary tree through a recursive function
int BinSearchTree::size() {
	return recSize(root);
}

// Recursively get's the number of nodes in a binary tree
int BinSearchTree::recSize(TreeNode *root) {
	// If we get to the bottom of a branch, just return 0
	if (root == nullptr) {
		return 0;
	}
	
	int leftSize = recSize(root->leftSubtree());
	int rightSize = recSize(root->rightSubtree());
	
	// Ad the sizes of both subtrees and the current node`
	return 1 + leftSize + rightSize;
}

// Prints out the keys in the tree in order via a helper function
void BinSearchTree::inorderDump() {
	recInOrderDump(root);
}

// Helper function which prints the nodes in a binary tree in order 
void BinSearchTree::recInOrderDump(TreeNode *root) {
	// If we reach the end of a branch, go up the stack
	if (root == nullptr) {
		return;
	}
	
	// Print the values smaller than root, then root, then the values
	// bigger than root
	recInOrderDump(root->leftSubtree());
	std::cout << root->value() << std::endl;
	recInOrderDump(root->rightSubtree());
}

// Gets the depth of the deepest node via a helper functionk
int BinSearchTree::maxDepth() {
	return recDepth(root);
}

// Recursively finds the depth of the  deepest node in root
int BinSearchTree::recDepth(TreeNode *root) {
	// If we reach the bottom of a branch
	// The depth below us is 0
	if (root == nullptr) {
		return 0;
	}
	
	int leftSize = recDepth(root->leftSubtree());
	int rightSize = recDepth(root->rightSubtree());
	
	// Return the depth of the branch which is larger
	if (leftSize >= rightSize) {
		return leftSize + 1;
	} else {
		return rightSize + 1;
	}
}