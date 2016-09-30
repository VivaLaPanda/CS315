#include "gcd.hpp"


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
}