#include "tree_node.h"

TreeNode::TreeNode() :
	left(nullptr),
	right(nullptr)
{
	pair.character = '\0';
	pair.frequency = 0;
}

TreeNode::TreeNode(Pair _pair, TreeNode* left, TreeNode* right) :
	left(left), right(right)
{
	pair.frequency = _pair.frequency;
	pair.character = _pair.character;
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
		cout << "(" << pair.frequency << " , " << pair.character << ") ";
		if (right) {
			right->inOrder();
		}
	}
}

void TreeNode::getHuffmanCode(string to_print, int& counter) {
	if (this) {
		if (left || right) {
			to_print.push_back('0');
			left->getHuffmanCode(to_print, counter);
			to_print.pop_back();

			to_print.push_back('1');
			right->getHuffmanCode(to_print, counter);
			to_print.pop_back();
		}
		else {
			if (pair.character == '\n') {
				if (to_print.size() == 0) { to_print.push_back('0'); }
				cout << "'\\n' - " << to_print << endl;
				counter += pair.frequency * to_print.size();
			}
			else {
				if (to_print.size() == 0) { to_print.push_back('0'); }
				cout << "'" << pair.character << " ' - " << to_print << endl;
				counter += pair.frequency * to_print.size();
			}
		}
	}
}