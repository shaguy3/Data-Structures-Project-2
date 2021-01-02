#include "binary_search_tree.h"

BST::BST() :
	root(nullptr)
{}

BST::~BST() {
	if (root) { delete root; }
}

TreeNode* BST::Find(char key) {
	TreeNode* node = root;
	while (node) {
		if (node->getPair().character == key) {
			return node;
		}
		else if (node->getPair().character > key) {
			node = node->Left();
		}
		else {
			node = node->Right();
		}
	}
	return nullptr;
}

TreeNode* BST::Min(TreeNode* _root) {
	TreeNode* cur_min = _root;
	while (cur_min->Left()) {
		cur_min = cur_min->Left();
	}
	return cur_min;
}

TreeNode* BST::Max(TreeNode* _root) {
	TreeNode* cur_max = _root;
	while (cur_max->Right()) {
		cur_max = cur_max->Right();
	}
	return cur_max;
}

bool BST::Insert(char key) {
	TreeNode* node = root;
	TreeNode* parent = nullptr;
	TreeNode* new_node = nullptr;

	while (node) {
		parent = node;
		if (key == node->getPair().character) {
			node->addFreq();
			return true;
		}
		else if (key < node->getPair().character) {
			node = node->Left();
		}
		else {
			node = node->Right();
		}
	}

	new_node = new TreeNode({ 1, key }, nullptr, nullptr);
	if (!parent) {
		root = new_node;
	}
	else {
		if (new_node->getPair().character < parent->getPair().character) {
			parent->setLeft(new_node);
		}
		else {
			parent->setRight(new_node);
		}
	}
	num_of_nodes++;
	return true;
}

TreeNode* BST::Delete(char key) {
	TreeNode* deleted = nullptr;
	TreeNode* cur_node = root;
	TreeNode* parent = nullptr;

	while (cur_node) {
		if (cur_node->getPair().character == key) {
			deleted = cur_node;
			if (!cur_node->Left() && !cur_node->Right()) { // If the deleted node is a leaf
				if (parent) {
					if (parent->Left() == cur_node) {
						parent->setLeft(nullptr);
					}
					else {
						parent->setRight(nullptr);
					}
				}
				else {
					root = nullptr;
				}
			}
			else if (!cur_node->Left()) { // If the deleted node has only a right child
				if (parent) {
					if (parent->Left() == cur_node) {
						parent->setLeft(cur_node->Right());
					}
					else {
						parent->setRight(cur_node->Right());
					}
				}
				else {
					root = cur_node->Right();
				}
			}
			else if (!cur_node->Right()) { // If the deleted node has only a left child
				if (parent) {
					if (parent->Left() == cur_node) {
						parent->setLeft(cur_node->Left());
					}
					else {
						parent->setRight(cur_node->Left());
					}
				}
				else {
					root = cur_node->Left();
				}
			}
			else { // If the deleted node has two children
				TreeNode* left_max = cur_node->Left();
				TreeNode* left_max_parent = cur_node;
				while (left_max->Right()) {
					left_max_parent = left_max;
					left_max = left_max->Right();
				}
				
				// Swapping between the left_max's and the current node's pairs.
				Pair tmp = cur_node->getPair();
				cur_node->setPair(left_max->getPair());
				left_max->setPair(tmp);
				
				deleted = left_max; // Returning the swapped pair
				left_max_parent->setRight(left_max->Left());
			}
			num_of_nodes--;
			return deleted;
		}
		else if (cur_node->getPair().character > key) {
			parent = cur_node;
			cur_node = cur_node->Left();
		}
		else {
			parent = cur_node;
			cur_node = cur_node->Right();
		}
	}

	return nullptr;
}

TreeNode* BST::DeleteMin() {
	TreeNode* cur_min = root;
	TreeNode* parent = nullptr;

	if (cur_min) {
		while (cur_min->Left()) {
			parent = cur_min;
			cur_min = cur_min->Left();
		}

		if (!cur_min->Left() && !cur_min->Right()) { // If the deleted node is a leaf
			if (parent) {
				parent->setLeft(nullptr);
			}
			else {
				root = nullptr;
			}
		}
		else if (!cur_min->Left()) { // If the deleted node has only a right child
			if (parent) {
				parent->setLeft(cur_min->Right());
			}
			else {
				root = cur_min->Right();
			}
		}

		num_of_nodes--;
		return cur_min;
	}

	return nullptr;
}

void BST::inOrder() {
	root->inOrder();
}