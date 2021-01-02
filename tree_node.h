#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef struct {
	int frequency;
	char character;
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
	const Pair& getPair() const { return pair; }
	TreeNode* Left() const { return left; }
	TreeNode* Right() const { return right; }
	
	/* setters */
	bool setPair(Pair _pair) { pair.frequency = _pair.frequency; \
							   pair.character = _pair.character; \
							   return true; }
	bool setLeft(TreeNode* node) { left = node; return true; }
	bool setRight(TreeNode* node) { right = node; return true; }
	bool addFreq() { pair.frequency++; return true; }

	/* prints */
	void inOrder();
	void getHuffmanCode(string to_print, int& counter);
};