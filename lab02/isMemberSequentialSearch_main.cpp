#include "isMemberSequentialSearch.hpp"

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
}