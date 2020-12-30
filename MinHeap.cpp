#include "MinHeap.h"
MinHeap::MinHeap(int n)
{
	arr = new Pair[n];
	logSize = 0;
	realSize = n;
	allocated = true;
}
MinHeap::~MinHeap()
{
	if (allocated)
	{
		delete[] arr;
	}
	arr = nullptr;
}

int MinHeap::getLeft(int node) { return (node*2+1); }
int MinHeap::getRight(int node) { return (node*2+2); }
int MinHeap::getParent(int node) { return ((node - 1) / 2); }

void MinHeap::swap(Pair& a, Pair& b)
{
	Pair tmp;
	tmp.frequency = a.frequency;
	tmp.charecter = a.charecter;
	a.frequency = b.frequency;
	a.charecter = b.charecter;
	b.frequency = tmp.frequency;
	b.charecter = tmp.charecter;
}

void MinHeap::fixHeap(int node)
{
	int min;
	int left = getLeft(node);
	int right = getRight(node);

	if (left<logSize && arr[left].frequency<arr[node].frequency)
	{
		min = left;
	}
	else
	{
		min = node;
	}
	if (right<logSize && arr[right].frequency<arr[min].frequency)
	{
		min = right;
	}

	if (min!=node)
	{
		swap(arr[node],arr[min]);
		fixHeap(min);
	}
}

Pair MinHeap::deleteMin()
{
	if (logSize==0)
	{
		Pair err;
		err.frequency = -1;
		err.charecter = -1;
		return err;
	}
	Pair min = arr[0];
	logSize--;
	arr[0] = arr[logSize];
	fixHeap(0);
	return min;
}

void MinHeap::insertMin(Pair node)
{
	if (logSize == realSize)
	{
		realSize *= 2;
		Pair* newarr = new Pair[realSize];
		for (int i = 0; i < logSize; i++)
		{
			newarr[i].frequency = arr[i].frequency;
			newarr[i].charecter = arr[i].charecter;
		}
		if (allocated)
		{
			delete[] arr;
		}
		arr = newarr;
	}
	int i = logSize;
	logSize++;
	while (i>0 && arr[getParent(i)].frequency>node.frequency)
	{
		arr[i] = arr[getParent(i)];
		i = getParent(i);
	}
	arr[i] = node;
}

MinHeap::MinHeap(Pair* A, int n)
{
	realSize = logSize = n;
	arr = A;
	allocated = false;
	for (int i = n/2-1; i >= 0; i--)
	{
		fixHeap(i);
	}
}

Pair MinHeap::getMin(){	return arr[0];}

bool MinHeap::isEmpty()
{
	if (logSize==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Pair MinHeap::getPairById(int n) { return arr[n]; }
