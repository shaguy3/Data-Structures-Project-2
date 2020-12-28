#pragma once
#include "tree_node.h"

using namespace std;

class BTree {
private:
	TreeNode* root;

public:
	/* Constructors and destructors */
	BTree();
	~BTree();

	/* Getters */
	TreeNode* Root() const { return root; }
	
	/* Prints */
	void InOrder() const { root->inOrder(); }
};