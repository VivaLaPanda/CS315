/*
  Author: Adrian Smith
  Course: CS 315
  Assignment: Lab 03 Part B
*/  

// Forward declaration of TreeNode class below.
// Since BinSearchTree uses TreeNode pointers rather
// than objects, we can get away with this in the .hpp.
// You should include "TreeNode.hpp" from the .cpp
class TreeNode;

class BinSearchTree {
	public:
	   void insert( int v );
	   bool find( int v );
	   bool iterFind( int v );
	   int size();
	   void inorderDump();
	   int maxDepth();

	private:
	   TreeNode *local_insert( TreeNode *, int );
	   TreeNode *root;
	   bool recFind( TreeNode *, int );
	   int recSize(TreeNode *);
	   void recInOrderDump(TreeNode *);
	   int recDepth(TreeNode *);
};