bool isSortedIterative(int list[], int n)
{
	// list is an array with n elements. The function uses an
	// iterative algorithm to return true if the numbers in the array are sorted from
	// the smallest (list[0]) to the largest (list[n-1]). An empty
	// list is a sorted list!
	
	for (int i = 0; i < (n - 1); i++)
	{
		if (list[i] > list[i+1])
		{
			return false;
		}
	}
	
	return true;
}


bool isSortedRecursive(int list[], int n)
{
	// list is an array with n elements. The function uses a
	// recursive algorithm to return true if the numbers in the array are sorted from
	// the smallest (list[0]) to the largest (list[n-1]). An empty
	// list is a sorted list!
	
	if (n <= 1)
		return true;
	
	if (list[n-1] < list[n-2])
		return false;
	
	return isSortedRecursive(list, n - 1);
}