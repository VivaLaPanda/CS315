#include "isMemberBinarySearch.hpp"

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
}