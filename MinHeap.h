#pragma once
#include "tree_node.h"


class MinHeap
{
	private:
		TreeNode** arr;
		int logSize;
		int realSize;
		static int getLeft(int node);
		static int getRight(int node);
		static int getParent(int node);
		bool allocated;
	public:
		MinHeap(int n);
		MinHeap(TreeNode** A, int n);
		~MinHeap();
		void insertMin(TreeNode* node);
		TreeNode* deleteMin();
		bool isEmpty();
		void fixHeap(int node);
		TreeNode* getMin();
		void swap(TreeNode*& a, TreeNode*& b);
		TreeNode* getPairById(int n);
		int getfreq(int n);
		int getSize() { return logSize; }
};
