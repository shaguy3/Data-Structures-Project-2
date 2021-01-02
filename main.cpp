#include "binary_search_tree.h"
#include "MinHeap.h"
#include "binary_tree.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

BST* readFile() {
	string filename;
	cout << "Please enter the name of the input file: ";
	cin >> filename;

	ifstream in;
	in.open(filename);

	BST* tree = new BST();
	char ch = '\0';

	while (!in.eof()) {
		if (!in.good()) {
			cout << "Error reading" << endl;
			exit(-1);
		}

		in >> ch;
		tree->Insert(ch);
	}
	in.close();

	return tree;
}

MinHeap* buildHeapFromBST(BST* search_tree) {
	MinHeap* min_heap = new MinHeap(search_tree->getNumOfNodes());
	while (search_tree->getRoot()) {
		min_heap->insertMin(search_tree->DeleteMin());
	}

	return min_heap;
}

TreeNode* buildHuffmanTree(MinHeap* min_heap) {
	TreeNode* new_node;

	int heap_size = min_heap->getSize();
	for (int i = 1; i < heap_size; i++) {
		new_node = new TreeNode();

		new_node->setLeft(min_heap->deleteMin());
		new_node->setRight(min_heap->deleteMin());
		new_node->setPair({ new_node->Left()->getPair().frequency + new_node->Right()->getPair().frequency , '\0' });

		min_heap->insertMin(new_node);
	}

	return min_heap->deleteMin();
}

int main() {

	BST* search_tree = readFile();

	cout << "Printing tree: " << endl;
	search_tree->inOrder();
	cout << endl << endl;

	MinHeap* min_heap = buildHeapFromBST(search_tree);

	BTree* huffman_tree = new BTree();
	huffman_tree->setRoot(buildHuffmanTree(min_heap));

	string to_print;
	huffman_tree->Root()->getHuffmanCode(to_print);

	delete search_tree;
	delete min_heap;
}