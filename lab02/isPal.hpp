#ifndef _isPal_hpp
#define _isPal_hpp

#include<iostream>
#include<cstdlib>

bool isPalIterative(const char *s, int n); 
// s contains n characters. The function uses an iterative
// algorithm to determine if s contains a string that is a palindrome or
// not. 
bool isPalRecursive(const char *s, int start, int n); 
// s contains n characters. The function uses a recursive
// algorithm to determine if s contains a string that is a palindrome or
// not. When the function is called for the first time,  start will
// contain zero, the index of the first element of s.

#endif