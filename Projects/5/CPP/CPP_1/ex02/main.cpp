#include <iostream>

int main( void ) {
	std::string str = "HI THIS IS BRAIN";

	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "[STR] Memory address: " << &str << std::endl;
	std::cout << "[stringPTR] Memory address: " << stringPTR << std::endl;
	std::cout << "[stringREF] Memory address: " << &stringREF << std::endl;
	
	std::cout << "[STR] Points to -> " << str << std::endl;
	std::cout << "[stringPTR] Points to -> " << *stringPTR << std::endl;
	std::cout << "[stringREF] Points to -> " << stringREF << std::endl;
}