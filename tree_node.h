#pragma once
#include <iostream>

using namespace std;

typedef struct {
	int frequency;
	char charecter;
}Pair;

class TreeNode {
private:
	Pair pair;
	TreeNode* left, * right;

public:
	/* Constructors and Destructors */
	TreeNode();
	TreeNode(Pair _pair, TreeNode* left, TreeNode* right);
	~TreeNode();

	/* getters */
	Pair getPair() const { return pair; }
	TreeNode* Left() const { return left; }
	TreeNode* Right() const { return right; }
	
	/* setters */
	bool setPair(Pair _pair) { pair.frequency = _pair.frequency; \
							   pair.charecter = _pair.charecter; \
							   return true; }
	bool setLeft(TreeNode* node) { left = node; return true; }
	bool setRight(TreeNode* node) { right = node; return true; }

	/* prints */
	void inOrder();
};