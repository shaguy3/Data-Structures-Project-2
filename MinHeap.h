#pragma once

class MinHeap
{
	private:
		Pair* arr;
		int logSize;
		int realSize;
		static int getLeft(int node);
		static int getRight(int node);
		static int getParent(int node);
		bool allocated;
	public:
		MinHeap(int n);
		MinHeap(Pair* A, int n);
		~MinHeap();
		void insertMin(Pair node);
		Pair deleteMin();
		bool isEmpty();
		void fixHeap(int node);
		Pair getMin();
		void swap(Pair& a, Pair& b);
};
