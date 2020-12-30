#include "binary_search_tree.h"
#include "MinHeap.h"
#include <iostream>

using namespace std;

void test_insert(BST* tree) {
	int freq = 0;
	char ch = '\0';
	
	cout << "choose a number and then a charecter to insert: " << endl;
	cin >> freq;
	cin >> ch;

	Pair pair = { freq, ch };
	tree->Insert(pair);
}

void test_delete(BST* tree) {
	int freq = 0;
	
	cout << "choose a key to delete: ";
	cin >> freq;

	TreeNode* deleted = tree->Delete(freq);
	if (!deleted) {
		cout << "Not found" << endl;
	}
	else {
		cout << "Deleted node is: " << deleted->getPair().frequency << ", " << deleted->getPair().charecter << endl;
	}
}

void test_find(BST* tree) {
	if (tree->getRoot()) {
		int freq = 0;

		cout << "choose a key to find: ";
		cin >> freq;

		TreeNode* found = tree->Find(freq);
		if (!found) {
			cout << "Not found" << endl;
		}
		else {
			cout << "Found node is: " << found->getPair().frequency << ", " << found->getPair().charecter << endl;
		}
	}
	else {
		cout << "Cant delete, the tree is empty" << endl;
	}
}

void test_delete_min(BST* tree) {
	if (!tree->getRoot()) {
		cout << "Cant delete, the tree is empty." << endl;
	}
	else {
		Pair deleted = tree->DeleteMin();
		cout << "Deleted pair is: " << deleted.frequency << ", " << deleted.charecter << endl;
	}
}

void print_tree(BST* tree) {
	tree->inOrder();
	cout << endl;
}

int main() {

	/* BST testing 
	BST* tree = new BST();

	int choice = 0;
	do {
		cout << "0: quit, 1: insert, 2: delete, 3: find, 4: delete min, 5: print tree. ";
		cin >> choice;
		if (choice == 1) {
			test_insert(tree);
		}
		else if (choice == 2) {
			test_delete(tree);
		}
		else if (choice == 3) {
			test_find(tree);
		}
		else if (choice == 4) {
			test_delete_min(tree);
		}
		else if (choice == 5) {
			print_tree(tree);
		}
	} while (choice != 0);
	*/
	// delete tree;

	/*Heap testing*/
	MinHeap* tst = new MinHeap(5);
	Pair a, b, c, d, e;
	a.charecter = 'a';
	a.frequency = 10;
	b.charecter = 'b';
	b.frequency = 12;
	c.charecter = 'c';
	c.frequency = 8;
	d.charecter = 'd';
	d.frequency = 4;
	e.charecter = 'e';
	e.frequency = 2;
	tst->insertMin(a);
	tst->insertMin(b);
	tst->insertMin(c);
	tst->insertMin(d);
	tst->insertMin(e);
	for (int i = 0; i < 5; i++)
	{
		Pair min = tst->getPairById(2);
	}
	
}