#include<iostream>

int gcdIterative(int a, int b)
{
	int temp;
	while (b % a != 0)
	{
		temp = b;
		b = a;
		a = temp % a; 
	}
	
	return a;
}

int gcdRecursive(int a, int b)
{
	if (b % a == 0)
		return a;
	
	return gcdRecursive( b % a, a );
}