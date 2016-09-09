#include<iostream>
#include<fstream>
#include<unistd.h>
#include<stdlib.h>

#include "LargerSet.hpp"

int main()
{
	LargerSet *miniSet = new LargerSet(32);
	LargerSet *normalSet = new LargerSet(64);
	// LargerSet *yuugeSet = new LargerSet(10000);
	
	miniSet->addElement(4);
	normalSet->addElement(63);
	// yuugeSet->addElement(10001);
	
	miniSet->printElements();
	normalSet->printElements();
	// yuugeSet->printElements();
	
	miniSet->addElement(30);
	normalSet->addElement(62);
	// yuugeSet->addElement(1);
	
	miniSet->printElements();
	normalSet->printElements();
	// yuugeSet->printElements();
	
	miniSet->deleteElement(4);
	normalSet->deleteElement(63);
	
	miniSet->printElements();
	normalSet->printElements();
	// yuugeSet->printElements();
	
    return 0;
}
