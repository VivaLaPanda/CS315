#ifndef _isMemberSequentialSearch_hpp
#define _isMemberSequentialSearch_hpp

#include<iostream>
#include<cstdlib>

bool isMemberSequentialSearchIterative(int list[], int n, int key);
// list contains n unordered elements. The function uses an iterative
// solution to determine if key is a member of the list or not. That is,
// it returns true if there is an i, 0 < i < n, 
// and list[i] == key. Otherwise, the function returns false.

bool isMemberSequentialSearchRecursive(int list[], int n, int key);
// list contains n unordered elements. The function uses a recursive
// solution to determine if key is a member of the list or not. That is,
// it returns true if there is an i, 0 < i < n, 
// and list[i] == key. Otherwise, the function returns false.

#endif