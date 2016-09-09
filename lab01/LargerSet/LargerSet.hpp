#include<iostream>

class LargerSet
{
public:
    // maxValue argument is the number of possible elements.
    // for example: maxValue is 100 for the range [0, 100)
    LargerSet(unsigned maxValue);

    ~LargerSet();
    bool addElement(unsigned int);      // add a new element to the set. No-op if input is invalid.
    bool deleteElement(unsigned int);   // delete an element from the set. No-op if not a member.
    bool isMember(unsigned int);    
    unsigned int numElements();   
    void printElements();               // prints members from smallest to largest.

private:
    unsigned long *set;                 // internal representation of our set.
    unsigned maxElementValue;
    unsigned numBuckets;
	unsigned elementCounter;

    LargerSet &operator=(const LargerSet &);   // disallow assignment
    LargerSet(const LargerSet &);              // disallow assignment
};