#include "lab01b_printBits_2.hpp"
#include<iostream>

/*
  This class provides set operations for a set whose elements are subsets of 
  [0, sizeof(unsigned long)*8). On a 64 bit machine, the range is [0, 64).

  The program uses an "unsigned long" to represent the subsets that it maintains.  
*/

class SmallSet
{
public:
    SmallSet(): set(0) {} 
    bool addElement(unsigned long);    // add a new element to the set. No-op if input is invalid.
    bool deleteElement(unsigned long); // delete an element from the set. No-op if not a member.
    bool isMember(unsigned long);      // test membership
    unsigned numElements();            // returns the cardinality of the set
    void printElements();              // prints members from smallest to largest.
    
private:
    unsigned long set;                // internal representation of our set.
	unsigned elementCounter; // Stores the number of elements in the set

    SmallSet &operator=( const SmallSet &);   // disallow assignment
    SmallSet( const SmallSet &);              // disallow copy-constructor
};
