#include <iostream>
#include <string>

int main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string* strPTR = &str;
	std::string& strREF = str;

	std::cout << "\nmemory addresses of the values:" << std::endl;

	std::cout	<< "string: " << &str << "\n"
				<< "string pointer: " << strPTR << "\n"
				<< "string reference: " << &strREF << std::endl;

	std::cout << "\nthe actual values are:" << std::endl;

	std::cout	<< "string: " << str << "\n"
				<< "string pointer: " << *strPTR << "\n"
				<< "string reference: " << strREF << "\n" << std::endl;

	return 0;
}
