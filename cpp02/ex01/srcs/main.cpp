#include "Fixed.hpp"

int main() {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "Regular tests:" << "\n";
	std::cout << "-------------------------" << std::endl;

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "Overflow tests:" << "\n";
	std::cout << "-------------------------" << std::endl;

	Fixed e(INT32_MAX);
	Fixed g(INT32_MIN);

	std::cout << "e is " << e << std::endl;
	std::cout << "g is " << g << std::endl;

	Fixed i(static_cast<float>(INT32_MAX));
	Fixed j(static_cast<float>(INT32_MIN));

	std::cout << "i is " << i << std::endl;
	std::cout << "j is " << j << std::endl;

	std::cout << "-------------------------" << std::endl;
	std::cout << "End tests." << "\n";

	return 0;
}
