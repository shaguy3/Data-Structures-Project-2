#include "binary_tree.h"

BTree::BTree() :
	root(nullptr)
{}

BTree::~BTree() {
	if (root) {
		delete root;
	}
}
