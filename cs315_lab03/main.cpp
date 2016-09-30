/*
  Author: Adrian Smith
  Course: CS 315
  Assignment: Lab 03 Part B
*/  

#include <iostream>
#include "TreeNode.hpp"
#include "BinSearchTree.hpp"

int main( int argc, char *argv[] ) {
	// create a tree and then print the values of its nodes 
	// from the smallest to the largest.

	// Making a new tree for testingk
	BinSearchTree *tree = new BinSearchTree();

	std::cout << "Please enter the values for the list, one per line. 0 terminates input." << std::endl;
	
	// User input a list of integers
	int v;
	while( std::cin >> v ) {
		if (v == 0)
			break;
		tree->insert( v );
	}
	
	std::cout << std::endl;
	
	// Output the list the user gave, in order
	std::cout << "Printing values in order:" << std::endl;
	tree->inorderDump();
	
	std::cout << std::endl;
	
	// Looking for a key recursively and iteratively
	int key;
	std::cout << "Finding: Recursive and then Iterative" << std::endl;
	std::cout << "Key to find: ";
	
	std::cin.clear();
	std::cin >> key;
	
	std::cout << std::endl;
	 
	std::cout << (tree->find(key) ? "Found" : "Not Found") << std::endl;	
	std::cout << (tree->iterFind(key) ? "Found" : "Not Found") << std::endl;
	
	std::cout << std::endl;
	
	// Checking the size and maximum depth
	std::cout << "Size of tree: ";
	std::cout << tree->size() << std::endl;
	
	std::cout << "Maximuim depth of tree: ";
	std::cout << tree->maxDepth() << std::endl;
	
	std::cout << std::endl;
	
	// Printing out one last time to ensure we didn't modify the tree
	std::cout << "Printing values in order:" << std::endl;
	tree->inorderDump();
	
	return 0;			    
}