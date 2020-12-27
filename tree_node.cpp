#include "tree_node.h"

TreeNode::TreeNode() :
	left(nullptr),
	right(nullptr)
{
	pair.frequency = 0;
	pair.charecter = '\0';
}

TreeNode::TreeNode(Pair _pair, TreeNode* left, TreeNode* right) :
	left(left), right(right)
{
	pair.frequency = _pair.frequency;
	pair.charecter = _pair.charecter;
}

TreeNode::~TreeNode() {
	if (left) { delete left; }
	if (right) { delete right; }
}

void TreeNode::inOrder() {
	if (this) {
		if (left) {
			left->inOrder();
		}
		cout << "(" << pair.frequency << ", " << pair.charecter << ") ";
		if (right) {
			right->inOrder();
		}
	}
}