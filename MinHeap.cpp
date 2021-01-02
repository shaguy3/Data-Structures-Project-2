#include "MinHeap.h"
MinHeap::MinHeap(int n)
{
	arr = new TreeNode * [n];
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


void MinHeap::swap(TreeNode*& a, TreeNode*& b)
{
	TreeNode* tmp = a;
	a = b;
	b = tmp;
}

void MinHeap::fixHeap(int node)
{
	int min;
	int left = getLeft(node);
	int right = getRight(node);

	if ((left<logSize) && (arr[left]->getPair().frequency < arr[node]->getPair().frequency))
	{
		min = left;
	}
	else
	{
		min = node;
	}
	if ((right<logSize) && (arr[right]->getPair().frequency < arr[min]->getPair().frequency))
	{
		min = right;
	}

	if (min!=node)
	{
		swap(arr[node],arr[min]);
		fixHeap(min);
	}
}

TreeNode* MinHeap::deleteMin()
{
	if (logSize==0)
		return nullptr;
	
	TreeNode* min = arr[0];
	logSize--;
	arr[0] = arr[logSize];
	fixHeap(0);
	return min;
}

void MinHeap::insertMin(TreeNode* node)
{
	if (logSize == realSize)
	{
		realSize *= 2;
		TreeNode** newarr = new TreeNode * [realSize];
		for (int i = 0; i < logSize; i++)
		{
			newarr[i] = new TreeNode(arr[i]->getPair(), nullptr, nullptr);
		}
		if (allocated)
		{
			delete[] arr;
		}
		arr = newarr;
	}
	int i = logSize;
	logSize++;
	while (i>0 && arr[getParent(i)]->getPair().frequency>node->getPair().frequency)
	{
		arr[i] = arr[getParent(i)];
		i = getParent(i);
	}
	arr[i] = node;
}

MinHeap::MinHeap(TreeNode** A, int n)
{
	realSize = logSize = n;
	arr = A;
	allocated = false;
	for (int i = n/2-1; i >= 0; i--)
	{
		fixHeap(i);
	}
}

TreeNode* MinHeap::getMin() { return arr[0]; }

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

TreeNode* MinHeap::getPairById(int n) { return arr[n]; }

int MinHeap::getfreq(int n) { return arr[n]->getPair().frequency; }