#include "collatz.hpp"


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
}