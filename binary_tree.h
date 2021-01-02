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

	/* Setters */
	bool setRoot(TreeNode* node) { root = node; return true; }
	
	/* Prints */
	void InOrder() const {
		
	}
};