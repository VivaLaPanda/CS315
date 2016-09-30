#ifndef _gcd_hpp
#define _gcd_hpp

#include<iostream>
#include<cstdlib>

int gcdIterative(int a, int b);
// pre-condition: a < b is true.
// The function finds and returns the gcd of a and b using an
// iterative solution.

int gcdRecursive(int a, int b);
// pre-condition: a < b is true.
// The function finds and returns the gcd of a and b using a
// recursive solution.

#endif