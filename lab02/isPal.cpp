#include<iostream>

bool isPalIterative(const char *s, int n)
{
	int half = n / 2;
	for (int i = 0; i < half; i++)
	{
		if (s[i] != s[n - 1])
		{
			return false;
		}
		
		n--;
	}
	
	return true;
}

bool isPalRecursive(const char *s, int start, int n)
{
	if (start > (n-1))
	{
		return true;
	}
	
	if (s[start] != s[n-1])
	{
		return false;
	}
	
	return isPalRecursive(s, start + 1, n - 1);
}