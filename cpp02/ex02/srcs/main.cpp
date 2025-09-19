#include "Fixed.hpp"

int main() {
	std::cout << "======================" << std::endl;
	std::cout << "   Basic arithmetic   " << std::endl;
	std::cout << "======================" << std::endl;

	Fixed a(10);
	Fixed b(3.5f);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;

	std::cout << "======================" << std::endl;
	std::cout << "   Comparisons        " << std::endl;
	std::cout << "======================" << std::endl;

	Fixed x(5.05f);
	Fixed y(5.05f);
	Fixed z(2);

	std::cout << x << " == " << y << " ? " << (x == y) << std::endl;
	std::cout << x << " != " << z << " ? " << (x != z) << std::endl;
	std::cout << z << " < " << x << " ? " << (z < x) << std::endl;
	std::cout << z << " <= " << x << " ? " << (z <= x) << std::endl;
	std::cout << x << " > " << z << " ? " << (x > z) << std::endl;
	std::cout << x << " >= " << y << " ? " << (x >= y) << std::endl;

	std::cout << "======================" << std::endl;
	std::cout << " Comparisons (false)" << std::endl;
	std::cout << "======================" << std::endl;

	Fixed c1(10);
	Fixed c2(20);

	std::cout << c1 << " > " << c2 << " ? " << (c1 > c2) << std::endl;
	std::cout << c1 << " >= " << c2 << " ? " << (c1 >= c2) << std::endl;
	std::cout << c2 << " < " << c1 << " ? " << (c2 < c1) << std::endl;
	std::cout << c2 << " <= " << c1 << " ? " << (c2 <= c1) << std::endl;
	std::cout << c1 << " == " << c2 << " ? " << (c1 == c2) << std::endl;
	std::cout << c1 << " != " << c1 << " ? " << (c1 != c1) << std::endl;

	std::cout << "======================" << std::endl;
	std::cout << "   Increment/Decrement" << std::endl;
	std::cout << "======================" << std::endl;

	Fixed inc(0);

	std::cout << "Start: " << inc << std::endl;
	std::cout << "++inc = " << ++inc << std::endl;
	std::cout << "After ++inc: " << inc << std::endl;
	std::cout << "inc++ = " << inc++ << std::endl;
	std::cout << "After inc++: " << inc << std::endl;
	std::cout << "--inc = " << --inc << std::endl;
	std::cout << "After --inc: " << inc << std::endl;
	std::cout << "inc-- = " << inc-- << std::endl;
	std::cout << "After inc--: " << inc << std::endl;

	std::cout << "======================" << std::endl;
	std::cout << "   Min / Max          " << std::endl;
	std::cout << "======================" << std::endl;

	Fixed f1(42.42f);
	Fixed f2(21.21f);

	std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
	std::cout << "min(f1, f2) = " << Fixed::min(f1, f2) << std::endl;
	std::cout << "max(f1, f2) = " << Fixed::max(f1, f2) << std::endl;

	const Fixed cf1(100.5f);
	const Fixed cf2(200.25f);

	std::cout << "const min(cf1, cf2) = " << Fixed::min(cf1, cf2) << std::endl;
	std::cout << "const max(cf1, cf2) = " << Fixed::max(cf1, cf2) << std::endl;

	std::cout << "======================" << std::endl;
	std::cout << "   Edge Cases         " << std::endl;
	std::cout << "======================" << std::endl;

	Fixed neg(-15.5f);
	Fixed small(0.125f);

	std::cout << "neg = " << neg << std::endl;
	std::cout << "small = " << small << std::endl;
	std::cout << "neg + small = " << (neg + small) << std::endl;
	std::cout << "neg - small = " << (neg - small) << std::endl;
	std::cout << "neg * small = " << (neg * small) << std::endl;
	std::cout << "neg / small = " << (neg / small) << std::endl;

	Fixed divTest(1);
	Fixed tiny(0.0001f);
	//std::cout << "1 / 0.0001 ≈ " << (divTest / tiny) << std::endl;

	std::cout << "======================" << std::endl;
	std::cout << "   End of tests       " << std::endl;
	std::cout << "======================" << std::endl;

	return 0;
}
