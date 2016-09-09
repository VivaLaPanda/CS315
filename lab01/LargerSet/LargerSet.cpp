#include "LargerSet.hpp"

LargerSet::LargerSet(unsigned maxValue)

{
	// Initializes an array of unsigned longs which has
	// maxValue / (sizeof(unsigned long) * 8) indicies
	unsigned long temp = 0;
	maxElementValue = sizeof(temp) * 8;
	
	// "Round up" the number of buckets
	if (maxValue % maxElementValue == 0)
	{
		numBuckets = (maxValue / maxElementValue);
	}
	else
	{
		numBuckets = (maxValue / maxElementValue) + 1;
	}
	
	set =  new unsigned long [numBuckets];
	elementCounter = 0;
}

LargerSet::~LargerSet()
{
	delete this->set;
}

bool LargerSet::addElement(unsigned int newInt)
{
	// Checking to see if newInt is out of bounds.
	if (newInt > (maxElementValue * numBuckets))
	{
		return false;
	}
	
	// Determining which bucket to edit
	// Making a 1 bit at the <newInt> place
	unsigned int subValue = newInt % maxElementValue;
	unsigned long addVal = 1;
	addVal <<= subValue;
	
	// Checking to see if newInt is already a member
	if (!isMember(newInt))
	{
		elementCounter++;
	}
	
	// Editing the target bit on the target bucket
	set[newInt / maxElementValue] = set[newInt / maxElementValue] | addVal;
	return true;
}

bool LargerSet::deleteElement(unsigned int remInt)
{
	// Checking to see if newInt is out of bounds.
	if (remInt > (this->maxElementValue * this->numBuckets))
	{
		return false;
	}
	
	// Determining which bucket to edit
	// Making a 1 bit at the <newInt> place
	unsigned long subValue = remInt % this->maxElementValue;
	unsigned long remVal = 1;
	remVal <<= subValue;
	
	// Checking to see if newInt is already a member
	if (isMember(remInt))
	{
		this->elementCounter--;
	}
	
	// Editing the target bit on the target bucket
	this->set[remInt / this->maxElementValue] = this->set[remInt / this->maxElementValue] & ~remVal;
	
	return true;
}

bool LargerSet::isMember(unsigned int targetInt)
{
	// Checking to see if newInt is out of bounds.
	if (targetInt > (maxElementValue * numBuckets))
	{
		return false;
	}
	
	// Determining which bucket to edit
	// Making a 1 bit at the <newInt> place
	unsigned long subValue = targetInt % this->maxElementValue;
	unsigned long targetVal = 1;
	targetVal <<= subValue;
	
	// Editing the target bit on the target bucket
	return set[targetInt / maxElementValue] & targetVal;
}
      
unsigned int LargerSet::numElements()
{
	return this->elementCounter;
}
   
void LargerSet::printElements()
{
    // Checks if each index has a value in it, and prints the results
	for (int j = 0; j < this->numBuckets; j++)
	{
		unsigned long subSet = this->set[j];
		unsigned long valChecker = 1;
		for (int i = 0; i < (sizeof(subSet) * 8); i++)
		{
			if (subSet & valChecker)
			{
				// Printing the index we found a num at
				std::cout << i << std::endl;
			}
			
			valChecker <<= 1;
		}
	}
}

