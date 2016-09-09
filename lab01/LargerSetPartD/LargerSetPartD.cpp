#include "LargerSetPartD.hpp"

LargerSetPartD::LargerSetPartD(unsigned maxValue)
{
	// Initializes an array of unsigned longs which has
	// maxValue / (sizeof(unsigned long) * 8) indicies
	unsigned long temp = 0;
	this->bucketSize = sizeof(temp) * 8;
	this->maxElementValue = maxValue;
	
	// "Round up" the number of buckets
	if (this->maxElementValue % this->bucketSize == 0)
	{
		this->numBuckets = (this->maxElementValue / this->bucketSize);
	}
	else
	{
		this->numBuckets = (this->maxElementValue / this->bucketSize) + 1;
	}
	
	// Initializing set
	this->set =  new unsigned long [this->numBuckets];
	
	// Clearing all buckets
	for (int i = 0; i < this->numBuckets; i++)
	{
		this->set[i] = 0;
	}
	
	this->elementCounter = 0;
}

LargerSetPartD::~LargerSetPartD()
{
	this->elementCounter = 0;
	delete []this->set;
}

bool LargerSetPartD::addElement(unsigned int newInt)
{
	// Checking to see if newInt is out of bounds.
	if (newInt > (bucketSize * numBuckets))
	{
		std::cout << "New integer is too large" << std::endl;
		return false;
	}
	
	// Determining which bucket to edit
	// Making a 1 bit at the <newInt> place
	unsigned int subValue = newInt % bucketSize;
	unsigned long addVal = 1;
	addVal <<= subValue;
	
	// Checking to see if newInt is already a member
	if (!isMember(newInt))
	{
		this->elementCounter++;
	}
	
	// Editing the target bit on the target bucket
	set[newInt / bucketSize] = set[newInt / bucketSize] | addVal;
	return true;
}

bool LargerSetPartD::deleteElement(unsigned int remInt)
{
	// Checking to see if newInt is out of bounds.
	if (remInt > (this->bucketSize * this->numBuckets))
	{
		return false;
	}
	
	// Determining which bucket to edit
	// Making a 1 bit at the <newInt> place
	unsigned long subValue = remInt % this->bucketSize;
	unsigned long remVal = 1;
	remVal <<= subValue;
	
	// Checking to see if newInt is already a member
	if (isMember(remInt))
	{
		this->elementCounter--;
	}
	
	// Editing the target bit on the target bucket
	this->set[remInt / this->bucketSize] = this->set[remInt / this->bucketSize] & ~remVal;
	
	return true;
}

// Takes the union of two large sets
void LargerSetPartD::set_union(const LargerSetPartD &otherSet)
{
	unsigned long *temp = this->MakeTemp(otherSet);
	
	for (int i = 0; i < otherSet.numBuckets; i++)
	{
		temp[i] |= otherSet.set[i];
	}
	for (int i = 0; i < this->numBuckets; i++)
	{
		temp[i] |= this->set[i];
	}
	
	delete this->set;
	if (this->numBuckets < otherSet.numBuckets)
		this->numBuckets = otherSet.numBuckets;
	
	this->set = temp;
	this->RecountElements();
}

// Takes the intersection of two large sets
void LargerSetPartD::intersection(const LargerSetPartD &otherSet)
{
	unsigned long *temp = this->MakeTemp(otherSet);
	if (otherSet.numBuckets , this->numBuckets)
	{
		for (int i = 0; i < otherSet.numBuckets; i++)
		{
			temp[i] = otherSet.set[i] & this->set[i];
		}
	}
	else
	{
		for (int i = 0; i < this->numBuckets; i++)
		{
			temp[i] = otherSet.set[i] & this->set[i];
		}
	}
	
	delete this->set;
	
	this->set = temp;
	this->RecountElements();
}



// Takes the difference of two large sets
void LargerSetPartD::difference(const LargerSetPartD &otherSet)
{
	std::cout << set[0] << std::endl;
	std::cout << otherSet.set[0] << std::endl;
	int index = 0;
	if (numBuckets > otherSet.numBuckets)
	{
		index = otherSet.numBuckets;
	}
	else
	{
		index = numBuckets;
	}
	
	for (int i = 0; i < index; i++)
	{
		/* for (unsigned long j = 1; j; j <<=1 )
		{
			if (otherSet.set[i] & j)
				this->set[i] &= ~(this->set[i] & j);
		} */
		
		set[i] &= ~(set[i] & otherSet.set[i]);
	}
	std::cout << set[0] << std::endl;
	std::cout << otherSet.set[0] << std::endl;
	
	this->RecountElements();
}

// Takes the compliment of all valid indicies
void LargerSetPartD::complement()
{	
	// How many elements in the last bucket
	int lastBucketFill = this->maxElementValue % this->bucketSize;
	
	// Inverting all buckets except for the last one
	for (int i = 0; i < this->numBuckets - 1; i++)
	{
		this->set[i] = ~this->set[i];
	}
	
	// Making invert mask
	unsigned long invertMask = ~0;
	invertMask >>= (this->bucketSize - lastBucketFill);
	
	// Inverting last bucket
	this->set[this->numBuckets - 1] ^= invertMask;
	
	this->RecountElements();
}

void LargerSetPartD::RecountElements()
{
	this->elementCounter = 0;
	// Checks if each index has a value in it, and prints the results
	for (int j = 0; j < this->numBuckets; j++)
	{
		unsigned long subSet = this->set[j];
		unsigned long valChecker = 1;
		for (int i = 0; i < (sizeof(subSet) * 8); i++)
		{
			if (subSet & valChecker)
			{
				this->elementCounter++;
			}
			
			valChecker <<= 1;
		}
	}
}

unsigned long * LargerSetPartD::MakeTemp(const LargerSetPartD &otherSet)
{
	
	// Making both arrays the same size
	if (otherSet.numBuckets <= this->numBuckets)
	{
		unsigned long *temp = new unsigned long [this->numBuckets];
		for (int i = 0; i < this->numBuckets; i++)
		{
			temp[i] = 0;
		}
		
		return temp;
	}
	
	unsigned long *temp = new unsigned long [otherSet.numBuckets];
	for (int i = 0; i < otherSet.numBuckets; i++)
	{
		temp[i] = 0;
	}
	
	return temp;
}

bool LargerSetPartD::isMember(unsigned int targetInt)
{
	// Checking to see if newInt is out of bounds.
	if (targetInt > (bucketSize * numBuckets))
	{
		return false;
	}
	
	// Determining which bucket to edit
	// Making a 1 bit at the <newInt> place
	unsigned long subValue = targetInt % this->bucketSize;
	unsigned int targetIndex = (targetInt / bucketSize);
	unsigned long targetVal = 1;
	targetVal <<= subValue;
	
	// Editing the target bit on the target bucket
	return set[targetIndex] & targetVal;
}
      
unsigned int LargerSetPartD::numElements()
{
	return this->elementCounter;
}
   
void LargerSetPartD::printElements()
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
				std::cout << (i * bucketSize) + j << std::endl;
			}
			
			valChecker <<= 1;
		}
	}
}