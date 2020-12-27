#pragma once
#include "tree_node.h"

class BST {
private:
	TreeNode* root;

public:
	/* Constructors and destructors */
	BST();
	~BST();

	/* getters */
	TreeNode* getRoot() const { return root; }

	/* Basic BST functions */
	TreeNode* Find(int key);
	bool Insert(Pair item);
	TreeNode* Delete(int key);
	Pair DeleteMin();

	/* Min and Max*/
	TreeNode* Min(TreeNode* _root); // Find Min relative to the provided _root
	TreeNode* Max(TreeNode* _root); // Find Max relative to the provided _root
	
	/* Prints */
	void inOrder();
};