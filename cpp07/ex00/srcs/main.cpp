#include "whatever.hpp"
#include <iostream>
#include <string>

#define C_G		"\033[0;32m\001"
# define C_RST	"\033[0m\002"

void test1() {
	char a = 'a';
	char b = 'b';

	std::cout << "before: " << a << ", " << b << std::endl;
	::swap(a, b);
	std::cout << "after: " << a << ", " << b << std::endl;

	char c = 'a';
	char d = 'e';

	std::cout << "min: " << ::min(c, d) << std::endl;
	std::cout << "max: " << ::max(c, d) << std::endl;
}

void test2() {
	int a = -20;
	int b = 44;

	std::cout << "before: " << a << ", " << b << std::endl;
	::swap(a, b);
	std::cout << "after: " << a << ", " << b << std::endl;

	std::cout << "min: " << ::min(a, b) << std::endl;
	std::cout << "max: " << ::max(a, b) << std::endl;
}

void test3() {
	float a = -20.23f;
	float b = 44.123f;

	std::cout << "before: " << a << "f" << ", " << b << "f" << std::endl;
	::swap(a, b);
	std::cout << "after: " << a << "f" << ", " << b << "f" << std::endl;

	std::cout << "min: " << ::min(a, b) << "f" << std::endl;
	std::cout << "max: " << ::max(a, b) << "f" << std::endl;
}

void test4() {
	double a = -97.087;
	double b = 55.9705;

	std::cout << "before: " << a << ", " << b << std::endl;
	::swap(a, b);
	std::cout << "after: " << a << ", " << b << std::endl;

	std::cout << "min: " << ::min(a, b) << std::endl;
	std::cout << "max: " << ::max(a, b) << std::endl;
}

void test5() {
	std::string a = "hello";
	std::string b = "hell!";

	std::cout << "before: " << a << ", " << b << std::endl;
	::swap(a, b);
	std::cout << "after: " << a << ", " << b << std::endl;

	std::cout << "min: " << ::min(a, b) << std::endl;
	std::cout << "max: " << ::max(a, b) << std::endl;
}

void test6() {
	void* x;
	void* y;
	int a;
	int b;

	x = &a;
	y = &b;
	std::cout << "before: " << x << ", " << y << std::endl;
	::swap(x, y);
	std::cout << "after: " << x << ", " << y << std::endl;

	std::cout << "min: " << ::min(x, y) << std::endl;
	std::cout << "max: " << ::max(x, y) << std::endl;
}

void test7() {
	bool a = true;
	bool b = false;

	std::cout << "before: " << a << ", " << b << std::endl;
	::swap(a, b);
	std::cout << "after: " << a << ", " << b << std::endl;

	std::cout << "min: " << ::min(a, b) << std::endl;
	std::cout << "max: " << ::max(a, b) << std::endl;
}

void test8() {
	int a = 10;
	int b = 10;

	std::cout << "before: " << a << ", " << b << std::endl;
	::swap(a, b);
	std::cout << "after: " << a << ", " << b << std::endl;

	std::cout << "min: " << ::min(a, b) << std::endl;
	std::cout << "max: " << ::max(a, b) << std::endl;
}

void test9() {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int main() {
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
	std::cout << "TEST CHARS" << std::endl;
	std::cout << C_G << std::string(20, '=') << "\n" << C_RST << std::endl;
	test1();
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
	std::cout << "TEST INTS" << std::endl;
	std::cout << C_G << std::string(20, '=') << "\n" << C_RST << std::endl;
	test2();
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
	std::cout << "TEST FLOATS" << std::endl;
	std::cout << C_G << std::string(20, '=') << "\n" << C_RST << std::endl;
	test3();
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
	std::cout << "TEST DOUBLES" << std::endl;
	std::cout << C_G << std::string(20, '=') << "\n" << C_RST << std::endl;
	test4();
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
	std::cout << "TEST STRINGS" << std::endl;
	std::cout << C_G << std::string(20, '=') << "\n" << C_RST << std::endl;
	test5();
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
	std::cout << "TEST VOID*" << std::endl;
	std::cout << C_G << std::string(20, '=') << "\n" << C_RST << std::endl;
	test6();
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
	std::cout << "TEST BOOLEAN" << std::endl;
	std::cout << C_G << std::string(20, '=') << "\n" << C_RST << std::endl;
	test7();
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
	std::cout << "TEST EQUAL VALUE INT" << std::endl;
	std::cout << C_G << std::string(20, '=') << "\n" << C_RST << std::endl;
	test8();
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
	std::cout << "TEST FROM SUBJECT" << std::endl;
	std::cout << C_G << std::string(20, '=') << "\n" << C_RST << std::endl;
	test9();
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
	std::cout << "END TESTS" << std::endl;
	std::cout << C_G << std::string(20, '=') << "\n" << C_RST << std::endl;

	return 0;
}
