#pragma once
#include "tree_node.h"

class BST {
private:
	TreeNode* root;
	int num_of_nodes = 0;

public:
	/* Constructors and destructors */
	BST();
	~BST();

	/* getters */
	TreeNode* getRoot() const { return root; }
	int getNumOfNodes() const { return num_of_nodes; }

	/* Basic BST functions */
	TreeNode* Find(char key);
	bool Insert(char key);
	TreeNode* Delete(char key);
	TreeNode* DeleteMin();

	/* Min and Max*/
	TreeNode* Min(TreeNode* _root); // Find Min relative to the provided _root
	TreeNode* Max(TreeNode* _root); // Find Max relative to the provided _root
	
	/* Prints */
	void inOrder();
};