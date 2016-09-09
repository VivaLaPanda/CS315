#include "SmallSet.hpp"
// Adrian Smitb - CS315 Lab01 Part B - 2016
// Method implementations

bool SmallSet::addElement(unsigned long newLong)
{
    // Adding new element by adding a 1 to the newLongth bit
	unsigned long max = sizeof(this->set) * 8;
    if (newLong > max)
    {
        return false;
    }

	// Placing a bit at the <newLong> place in a string of 0s
    unsigned long addVal = 1;
    addVal <<= newLong;

    // Checks to see if the new element is a member of the set
	// If it isn't we increment the element counter
	if (!isMember(newLong))
	{
		this->elementCounter += 1;
	}
	this->set = this->set | addVal;
	
    return true;
}

bool SmallSet::deleteElement(unsigned long remLong)
{
    // Removing an element by masking with &
	unsigned long max = sizeof(this->set) * 8;
    if (remLong > max)
    {
        return false;
    }

	// Placing a bit at the <remLong> place in a string of 0s
    unsigned long remVal = 1;
    remVal <<= remLong;

    // Checks to see if the new element is a member of the set
	// If it isn't we decrement the element counter
	if (isMember(remLong)) {
		this->elementCounter -= 1;
	}
	this->set = this->set & ~remVal;
	
    return true;
}

bool SmallSet::isMember(unsigned long targetLong)
{
    // Checking if targetLong is in the set
	unsigned long max = sizeof(this->set) * 8;
    if (targetLong > max)
    {
        return false;
    }

	// Placing a bit at the <targetLong> place in a string of 0s
    unsigned long targetVal = 1;
    targetVal <<= targetLong;
    
    return this->set & targetVal; 
}

unsigned SmallSet::numElements()
{	
    return elementCounter;
}

void SmallSet::printElements()
{
    // Checks if each index has a value in it, and prints the results
    unsigned long valChecker = 1;
    for (int i = 0; i < sizeof(this->set) * 8; i++)
    {
        if (this->set & valChecker)
        {
            // Printing the index we found a num at
            std::cout << i << std::endl;
        }
        
        valChecker <<= 1;
    }
}
