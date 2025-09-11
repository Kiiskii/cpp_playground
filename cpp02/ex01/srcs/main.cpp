#include "Fixed.hpp"

int main() {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "-------------------------" << std::endl;

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

	std::cout << "-------------------------" << std::endl;
	std::cout << "Extra tests:" << "\n";
	std::cout << "-------------------------" << std::endl;

	// Raw bits
	Fixed rawTest;
	rawTest.setRawBits(123456);
	std::cout << "rawTest raw bits = " << rawTest.getRawBits() << std::endl;
	std::cout << "rawTest as float = " << rawTest.toFloat() << std::endl;

	// Copy vs assignment
	Fixed copyTest(b);
	Fixed assignTest;
	assignTest = c;
	std::cout << "copyTest (from b) = " << copyTest << std::endl;
	std::cout << "assignTest (from c) = " << assignTest << std::endl;

	// Chained assignment
	Fixed x, y, z;
	x = y = z = Fixed(7.75f);
	std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;

	// Negative numbers
	Fixed negInt(-42);
	Fixed negFloat(-42.42f);
	std::cout << "negInt = " << negInt << " | as int = " << negInt.toInt() << std::endl;
	std::cout << "negFloat = " << negFloat << " | as int = " << negFloat.toInt() << std::endl;

	// Large numbers
	Fixed bigInt(1 << 20); // 1048576
	Fixed bigFloat(123456.789f);
	std::cout << "bigInt = " << bigInt << " | as int = " << bigInt.toInt() << std::endl;
	std::cout << "bigFloat = " << bigFloat << " | as int = " << bigFloat.toInt() << std::endl;

	// Precision check
	Fixed precise1(0.1f);
	Fixed precise2(0.2f);
	Fixed precise3(0.3f);
	std::cout << "0.1 stored = " << precise1 << std::endl;
	std::cout << "0.2 stored = " << precise2 << std::endl;
	std::cout << "0.3 stored = " << precise3 << std::endl;

	std::cout << "-------------------------" << std::endl;
	std::cout << "End tests." << "\n";

	return 0;
}
