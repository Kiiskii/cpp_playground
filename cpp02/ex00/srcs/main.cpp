#include "Fixed.hpp"

int main() {
	Fixed a; 		// call default constructor
	Fixed b(a);		// call copy constructor
	Fixed c;		// call default constructor

	c = b;			// call copy assignment operator

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
