#include<iostream>

class LargerSetPartD
{
public:
    // maxValue argument is the number of possible elements.
    // for example: maxValue is 100 for the range [0, 100)
    LargerSetPartD(unsigned maxValue);
    LargerSetPartD(const LargerSetPartD &);

    ~LargerSetPartD();
    bool addElement(unsigned int);      // add a new element to the set. No-op if input is invalid.
    bool deleteElement(unsigned int);   // delete an element from the set. No-op if not a member.
    bool isMember(unsigned int);
	void set_union(const LargerSetPartD &);
	void intersection(const LargerSetPartD &);
	void difference(const LargerSetPartD &);
	void complement();    
    unsigned int numElements();   
    void printElements();               // prints members from smallest to largest.

private:
    unsigned long *set;                 // internal representation of our set.
    unsigned maxElementValue;
    unsigned numBuckets;
	unsigned bucketSize;
	unsigned elementCounter;
	unsigned long * MakeTemp(const LargerSetPartD &);
	void RecountElements();

    LargerSetPartD &operator=(const LargerSetPartD &);   // disallow assignment
};