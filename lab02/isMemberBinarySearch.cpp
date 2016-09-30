#include "isMemberBinarySearch.hpp"

bool isMemberBinarySearchIterative(int list[], int n, int key)
{
	int i = 0;
	int middle = i + (((n - 1) - i) / 2);
	
	while(i < n)
	{
		if (list[middle] == key)
			return true;
		if (key < middle)
		{
			n = middle;
			middle = i + (((n - 1) - i) / 2);
		}
		else
		{
			i = middle + 1;
			middle = i + (((n - 1) - i) / 2);
		}
	}
	
	return false;
}

bool isMemberBinarySearchRecursive(int list[], int n, int key)
{
	return BinarySearchRecursive(list, 0, n, key);
}

bool BinarySearchRecursive(int list[], int start, int n, int key)
{
	int middle = start + (((n - 1) - start) / 2);
	if (list[middle] == key)
		return true;
	if (start > n)
		return false;
	
	if (key < middle)
	{
		return BinarySearchRecursive(list, start, middle, key);
	}
	else
	{
		return BinarySearchRecursive(list, middle + 1, n, key);
	}
}