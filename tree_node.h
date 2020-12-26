#pragma once

typedef struct {
	int key;
	char data;
}Pair;

class TreeNode {
private:
	Pair value;
	TreeNode* left, * right;

public:
	/* Constructors and Destructors */
	TreeNode();
	TreeNode(Pair item, TreeNode* left, TreeNode* right);
	~TreeNode();
	void inOrder();
};