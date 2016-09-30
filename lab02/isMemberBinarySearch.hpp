#ifndef _isMemberBinarySearch_hpp
#define _isMemberBinarySearch_hpp

#include<iostream>
#include<cstdlib>

bool isMemberBinarySearchIterative(int list[], int n, int key);
// list contains n ordered elements. The function uses an iterative
// solution to determine if key is a member of the list or not. That is,
// it returns true if there is an i, 0 < i < n, 
// and list[i] == key. Otherwise, the function returns false.

bool isMemberBinarySearchRecursive(int list[], int n, int key);
// list contains n ordered elements. The function uses a recursive
// solution to determine if key is a member of the list or not. That is,
// it returns true if there is an i, 0 < i < n, 
// and list[i] == key. Otherwise, the function returns false. Hint: you may
// have to define another function (a helper function) that would take more
// arguments that provided here. Think about the role of parameter first
// in the recursive function-prototype for the palindrome problem above.

bool BinarySearchRecursive(int list[], int start, int n, int key);

#endif