collatz_main.cpp                                                                                    0000600 0013634 0013636 00000001164 12766133703 013606  0                                                                                                    ustar   asmith                          asmith                                                                                                                                                                                                                 #include "collatz.hpp"


int main() {
	std::cout << "Collatz: 1" << std::endl;
	std::cout << "Iter:" << std::endl;
	collatzIterative(1);
	std::cout << "Rec:" << std::endl;
	collatzRecursive(1);
	std::cout << std::endl;
	
	std::cout << "Collatz: 2" << std::endl;
	std::cout << "Iter:" << std::endl;
	collatzIterative(2);
	std::cout << "Rec:" << std::endl;
	collatzRecursive(2);
	std::cout << std::endl;
	
	std::cout << "Collatz: 5" << std::endl;
	std::cout << "Iter:" << std::endl;
	collatzIterative(6);
	std::cout << "Rec:" << std::endl;
	collatzRecursive(6);
	std::cout << std::endl;
	
    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                            gcd.cpp                                                                                             0000600 0013634 0013636 00000000410 12766121221 011650  0                                                                                                    ustar   asmith                          asmith                                                                                                                                                                                                                 #include<iostream>

int gcdIterative(int a, int b)
{
	int temp;
	while (b % a != 0)
	{
		temp = b;
		b = a;
		a = temp % a; 
	}
	
	return a;
}

int gcdRecursive(int a, int b)
{
	if (b % a == 0)
		return a;
	
	return gcdRecursive( b % a, a );
}                                                                                                                                                                                                                                                        gcd_main.cpp                                                                                        0000600 0013634 0013636 00000000615 12766121347 012674  0                                                                                                    ustar   asmith                          asmith                                                                                                                                                                                                                 #include "gcd.hpp"


int main() {
	std::cout << "1, 1" << std::endl;
	std::cout << gcdIterative(1, 1) << std::endl;
	std::cout << std::endl;
	
	std::cout << "5, 16" << std::endl;
	std::cout << gcdIterative(5, 16) << std::endl;
	std::cout << std::endl;
	
	std::cout << "5, 15" << std::endl;
	std::cout << gcdIterative(5, 15) << std::endl;
	std::cout << std::endl;
	
    return 0;
}                                                                                                                   isMemberBinarySearch.cpp                                                                            0000600 0013634 0013636 00000001600 12766130763 015166  0                                                                                                    ustar   asmith                          asmith                                                                                                                                                                                                                 #include "isMemberBinarySearch.hpp"

bool isMemberBinarySearchIterative(int list[], int n, int key)
{
	int i = 0;
	int middle = i + (((n - 1) - i) / 2);
	
	while(i < n)
	{
		if (list[middle] == key)
			return true;
		if (key < middle)
		{
			n = middle;
			middle = i + (((n - 1) - i) / 2);
		}
		else
		{
			i = middle + 1;
			middle = i + (((n - 1) - i) / 2);
		}
	}
	
	return false;
}

bool isMemberBinarySearchRecursive(int list[], int n, int key)
{
	return BinarySearchRecursive(list, 0, n, key);
}

bool BinarySearchRecursive(int list[], int start, int n, int key)
{
	int middle = start + (((n - 1) - start) / 2);
	if (list[middle] == key)
		return true;
	if (start > n)
		return false;
	
	if (key < middle)
	{
		return BinarySearchRecursive(list, start, middle, key);
	}
	else
	{
		return BinarySearchRecursive(list, middle + 1, n, key);
	}
}                                                                                                                                isMemberBinarySearch_main.cpp                                                                       0000600 0013634 0013636 00000001462 12766134350 016174  0                                                                                                    ustar   asmith                          asmith                                                                                                                                                                                                                 #include "isMemberBinarySearch.hpp"

int main() {
	std::cout << "Looking for 6 in [1, 2, 3]" << std::endl;
	int test[3] = {1, 2, 3};
	std::cout << isMemberBinarySearchIterative(test, 3, 6) << std::endl;
	std::cout << isMemberBinarySearchRecursive(test, 3, 6) << std::endl;
	std::cout << std::endl;
	
	
	std::cout << "Looking for 6 in [1, 2, 6]" << std::endl;
	test[2] = 6;
	std::cout << isMemberBinarySearchIterative(test, 3, 6) << std::endl;
	std::cout << isMemberBinarySearchRecursive(test, 3, 6) << std::endl;
	std::cout << std::endl;
	
	std::cout << "Looking for 6 in []" << std::endl;
	int test3[1] = {1};
	std::cout << isMemberBinarySearchIterative(test3, 0, 6) << std::endl;
	std::cout << isMemberBinarySearchRecursive(test3, 0, 6) << std::endl;
	std::cout << std::endl;
	
    return 0;
}                                                                                                                                                                                                              isMemberSequentialSearch.cpp                                                                        0000600 0013634 0013636 00000000626 12766122516 016060  0                                                                                                    ustar   asmith                          asmith                                                                                                                                                                                                                 #include<iostream>

bool isMemberSequentialSearchIterative(int list[], int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (list[i] == key)
			return true;
	}
	
	return false;
}

bool isMemberSequentialSearchRecursive(int list[], int n, int key)
{
	if (n == 1)
		return false;
	
	if (list[n-1] == key)
		return true;
	
	return isMemberSequentialSearchRecursive(list, n - 1, key);
}                                                                                                          isMemberSequentialSearch_main.cpp                                                                   0000600 0013634 0013636 00000001535 12766134302 017060  0                                                                                                    ustar   asmith                          asmith                                                                                                                                                                                                                 #include "isMemberSequentialSearch.hpp"

int main() {
	std::cout << "Looking for 6 in [1, 2, 3]" << std::endl;
	int test1[3] = {1, 2, 3};
	std::cout << isMemberSequentialSearchIterative(test1, 3, 6) << std::endl;
	std::cout << isMemberSequentialSearchRecursive(test1, 3, 6) << std::endl;
	std::cout << std::endl;
	
	std::cout << "Looking for 6 in [1, 2, 6]" << std::endl;
	int test2[3] = {1, 2, 6};
	std::cout << isMemberSequentialSearchIterative(test2, 3, 6) << std::endl;
	std::cout << isMemberSequentialSearchRecursive(test2, 3, 6) << std::endl;
	std::cout << std::endl;
	
	std::cout << "Looking for 6 in []" << std::endl;
	int test3[1] = {1};
	std::cout << isMemberSequentialSearchIterative(test3, 0, 6) << std::endl;
	std::cout << isMemberSequentialSearchRecursive(test3, 0, 6) << std::endl;
	std::cout << std::endl;
	
    return 0;
}                                                                                                                                                                   isPal.cpp                                                                                           0000600 0013634 0013636 00000000647 12766115704 012210  0                                                                                                    ustar   asmith                          asmith                                                                                                                                                                                                                 #include<iostream>

bool isPalIterative(const char *s, int n)
{
	int half = n / 2;
	for (int i = 0; i < half; i++)
	{
		if (s[i] != s[n - 1])
		{
			return false;
		}
		
		n--;
	}
	
	return true;
}

bool isPalRecursive(const char *s, int start, int n)
{
	if (start > (n-1))
	{
		return true;
	}
	
	if (s[start] != s[n-1])
	{
		return false;
	}
	
	return isPalRecursive(s, start + 1, n - 1);
}                                                                                         isPal_main.cpp                                                                                      0000600 0013634 0013636 00000002211 12766114011 013167  0                                                                                                    ustar   asmith                          asmith                                                                                                                                                                                                                 #include "isPal.hpp"

std::string lowerAndRemoveNonLetterChars(std::string s)
{
    std::string lettersOnly = "";
    for(int i = 0; i < s.length(); i++ )
        if( isalpha(s[i]) )
            lettersOnly += tolower(s[i]);
    return lettersOnly;
}

void palcheck(std::string p)
{
    std::cout << "String: " << p << std::endl;
    if( isPalIterative(p.c_str(), p.length()) )
        std::cout << "Iterative version: is a palindrome.\n";
    else
        std::cout << "Iterative version: is not a palindrome.\n";

    if( isPalRecursive(p.c_str(), 0, p.length()) )
        std::cout << "Recursive version: is a palindrome.\n";
    else
        std::cout << "Recursive version: is not a palindrome.\n";

    std::cout << std::endl;
}

int main() {
    // "A man, a plan, a canal -- Panama"

    std::string palStr = lowerAndRemoveNonLetterChars(std::string("A man, a plan, a canal -- Panama"));

    // palindromes
    palcheck(palStr);
    palcheck("anna");
    palcheck("racecar");

    // not palindromes
    palcheck("anza");
    palcheck("racebar");
    palcheck("this is in no way a palindrome");
    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                       isSorted.cpp                                                                                        0000600 0013634 0013636 00000001464 12766124773 012740  0                                                                                                    ustar   asmith                          asmith                                                                                                                                                                                                                 bool isSortedIterative(int list[], int n)
{
	// list is an array with n elements. The function uses an
	// iterative algorithm to return true if the numbers in the array are sorted from
	// the smallest (list[0]) to the largest (list[n-1]). An empty
	// list is a sorted list!
	
	for (int i = 0; i < (n - 1); i++)
	{
		if (list[i] > list[i+1])
		{
			return false;
		}
	}
	
	return true;
}


bool isSortedRecursive(int list[], int n)
{
	// list is an array with n elements. The function uses a
	// recursive algorithm to return true if the numbers in the array are sorted from
	// the smallest (list[0]) to the largest (list[n-1]). An empty
	// list is a sorted list!
	
	if (n <= 1)
		return true;
	
	if (list[n-1] < list[n-2])
		return false;
	
	return isSortedRecursive(list, n - 1);
}                                                                                                                                                                                                            isSorted_main.cpp                                                                                   0000600 0013634 0013636 00000001657 12766106556 013747  0                                                                                                    ustar   asmith                          asmith                                                                                                                                                                                                                 #include "isSorted.hpp"

int main()
{
    int numInputValues;
    std::cin >> numInputValues;
    if( ! std::cin.good() )
        return 1;
    int *numbers = new int[numInputValues];
    int numRead = 0;
    for( int i = 0; i < numInputValues && std::cin >> numbers[numRead++]; i++ )
        ;
    if( numInputValues != numRead ) {
        std::cerr << "Wasn't able to read " << numInputValues << " values; read only " << numRead << " Terminating...\n";
        return 1;
    }
    if( isSortedIterative(numbers, numInputValues) )
        std::cout << "Iterative version: numbers are sorted.\n";
    else
        std::cout << "Iterative version: numbers are not sorted.\n";
    
    if( isSortedRecursive(numbers, numInputValues) )
        std::cout << "Recursive version: numbers are sorted.\n";
    else
        std::cout << "Recursive version: numbers are not sorted.\n";

    delete [] numbers;
    return 0;
}                                                                                 collatz.hpp                                                                                         0000600 0013634 0013636 00000000404 12766131634 012604  0                                                                                                    ustar   asmith                          asmith                                                                                                                                                                                                                 #ifndef _collatz_hpp
#define _collatz_hpp

#include<iostream>
#include<cstdlib>

void collatzIterative(int n);
// Generate a Collatz sequence for n iteratively

void collatzRecursive(int n);
// Generate a Collatz sequence for n recursively.

#endif                                                                                                                                                                                                                                                            gcd.hpp                                                                                             0000600 0013634 0013636 00000000614 12766116376 011702  0                                                                                                    ustar   asmith                          asmith                                                                                                                                                                                                                 #ifndef _gcd_hpp
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

#endif                                                                                                                    isMemberBinarySearch.hpp                                                                            0000600 0013634 0013636 00000002061 12766130453 015171  0                                                                                                    ustar   asmith                          asmith                                                                                                                                                                                                                 #ifndef _isMemberBinarySearch_hpp
#define _isMemberBinarySearch_hpp

#include<iostream>
#include<cstdlib>

bool isMemberBinarySearchIterative(int list[], int n, int key);
// list contains n ordered elements. The function uses an iterative
// solution to determine if key is a member of the list or not. That is,
// it returns true if there is an i, 0 < i < n, 
// and list[i] == key. Otherwise, the function returns false.

bool isMemberBinarySearchRecursive(int list[], int n, int key);
// list contains n ordered elements. The function uses a recursive
// solution to determine if key is a member of the list or not. That is,
// it returns true if there is an i, 0 < i < n, 
// and list[i] == key. Otherwise, the function returns false. Hint: you may
// have to define another function (a helper function) that would take more
// arguments that provided here. Think about the role of parameter first
// in the recursive function-prototype for the palindrome problem above.

bool BinarySearchRecursive(int list[], int start, int n, int key);

#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                               isMemberSequentialSearch.hpp                                                                        0000600 0013634 0013636 00000001420 12766121642 016055  0                                                                                                    ustar   asmith                          asmith                                                                                                                                                                                                                 #ifndef _isMemberSequentialSearch_hpp
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

#endif                                                                                                                                                                                                                                                isPal.hpp                                                                                           0000600 0013634 0013636 00000001121 12766113103 012170  0                                                                                                    ustar   asmith                          asmith                                                                                                                                                                                                                 #ifndef _isPal_hpp
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

#endif                                                                                                                                                                                                                                                                                                                                                                                                                                               isSorted.hpp                                                                                        0000600 0013634 0013636 00000000307 12766106507 012733  0                                                                                                    ustar   asmith                          asmith                                                                                                                                                                                                                 #ifndef _isSorted_hpp
#define _isSorted_hpp

#include<iostream>
#include<cstdlib>

extern bool isSortedIterative(int list[], int n);
extern bool isSortedRecursive(int list[], int n);

#endif                                                                                                                                                                                                                                                                                                                         makefile                                                                                            0000600 0013634 0013636 00000004766 12766131612 012136  0                                                                                                    ustar   asmith                          asmith                                                                                                                                                                                                                 
CFLAGS= -ggdb -std=c++11 -Wall -Wextra

# the first target ("all") is made by default.
# So, we list all targets that need to be made here.
all: isSorted.x isPal.x

# dependencies for isSorted
isSorted.x: isSorted.o isSorted_main.o
	g++ $(CFLAGS) -o isSorted.x isSorted.o isSorted_main.o

isSorted.o: isSorted.hpp isSorted.cpp
	g++ $(CFLAGS) -c -o isSorted.o isSorted.cpp

isSorted_main.o: isSorted.hpp isSorted_main.cpp
	g++ $(CFLAGS) -c -o isSorted_main.o isSorted_main.cpp

# dependencies for isPal
isPal.x: isPal.o isPal_main.o
	g++ $(CFLAGS) -o isPal.x isPal.o isPal_main.o

isPal.o: isPal.hpp isPal.cpp
	g++ $(CFLAGS) -c -o isPal.o isPal.cpp

isPal_main.o: isPal.hpp isPal_main.cpp
	g++ $(CFLAGS) -c -o isPal_main.o isPal_main.cpp

# dependencies for gcd
gcd.x: gcd.o gcd_main.o
	g++ $(CFLAGS) -o gcd.x gcd.o gcd_main.o

gcd.o: gcd.hpp gcd.cpp
	g++ $(CFLAGS) -c -o gcd.o gcd.cpp

gcd_main.o: gcd.hpp gcd_main.cpp
	g++ $(CFLAGS) -c -o gcd_main.o gcd_main.cpp

# dependencies for isMemberSequentialSearch
isMemberSequentialSearch.x: isMemberSequentialSearch.o isMemberSequentialSearch_main.o
	g++ $(CFLAGS) -o isMemberSequentialSearch.x isMemberSequentialSearch.o isMemberSequentialSearch_main.o

isMemberSequentialSearch.o: isMemberSequentialSearch.hpp isMemberSequentialSearch.cpp
	g++ $(CFLAGS) -c -o isMemberSequentialSearch.o isMemberSequentialSearch.cpp

isMemberSequentialSearch_main.o: isMemberSequentialSearch.hpp isMemberSequentialSearch_main.cpp
	g++ $(CFLAGS) -c -o isMemberSequentialSearch_main.o isMemberSequentialSearch_main.cpp

# dependencies for isMemberBinarySearch 
isMemberBinarySearch.x: isMemberBinarySearch.o isMemberBinarySearch_main.o
	g++ $(CFLAGS) -o isMemberBinarySearch.x isMemberBinarySearch.o isMemberBinarySearch_main.o

isMemberBinarySearch.o: isMemberBinarySearch.hpp isMemberBinarySearch.cpp
	g++ $(CFLAGS) -c -o isMemberBinarySearch.o isMemberBinarySearch.cpp

isMemberBinarySearch_main.o: isMemberBinarySearch.hpp isMemberBinarySearch_main.cpp
	g++ $(CFLAGS) -c -o isMemberBinarySearch_main.o isMemberBinarySearch_main.cpp

# dependencies for collatz 
collatz.x: collatz.o collatz_main.o
	g++ $(CFLAGS) -o collatz.x collatz.o collatz_main.o

collatz.o: collatz.hpp collatz.cpp
	g++ $(CFLAGS) -c -o collatz.o collatz.cpp

collatz_main.o: collatz.hpp collatz_main.cpp
	g++ $(CFLAGS) -c -o collatz_main.o collatz_main.cpp

# At the shell prompt, type: 
# make clean
# to remove the .o, .x and Emacs backup files.

clean:
	rm -f *.o *.x *~                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          