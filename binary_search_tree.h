#pragma once
#include "tree_node.h"

class BST {
private:
	TreeNode* root;

public:
	/* Constructors and destructors */
	BST();
	~BST();

	/* Basic BST functions */
	TreeNode* Find(Pair item);
	void Insert(Pair item);
	void Delete(int key);

	/* Prints */
	void inOrder();
};