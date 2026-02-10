#include "../inc/Array.hpp"
#include <exception>
#include <iostream>

template <typename T>
void printArray(const Array<T>& arr) {
	for (size_t i = 0; i < arr.size(); ++i) {
		std::cout << arr[i];
		if (i + 1 != arr.size())
			std::cout << " | ";
	}
	std::cout << std::endl;
}

void test1() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "BASIC TESTS" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	try {
		Array<int> a(3);

		a[0] = 123;
		a[1] = 456;
		a[2] = 789;

		Array<int> b(a);

		std::cout << "a: ";
		printArray(a);

		std::cout << "b: ";
		printArray(b);

		std::cout << a[10];
	}
	catch (const std::exception& e) {
		std::cout << C_R << "exception: " << e.what() << C_RST << std::endl;
	}
}

void test2() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "ASSIGNMENT OPERATOR TESTS" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	try {
		Array<int> a(3);

		a[0] = 123;
		a[1] = 456;
		a[2] = 789;

		Array<int> b(3);

		b[0] = 111;
		b[1] = 222;
		b[2] = 333;

		b = a;

		std::cout << "a before change: ";
		printArray(a);

		a[1] = 42;

		std::cout << "a after change: ";
		printArray(a);

		std::cout << "b after b = a (should NOT change when a changes): ";
		printArray(b);

		Array<int> tmp(b);
		b = tmp;
		std::cout << "b after self-assignment (should be unchanged): ";
		printArray(b);

		Array<int> empty;
		a = empty;
		std::cout << "a size should be 0: " << a.size() << std::endl;
		std::cout << "a[0] should throw: " << a[0];
	}
	catch (const std::exception& e) {
		std::cout << C_R << "exception: " << e.what() << C_RST << std::endl;
	}
}

void test3() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "CONST ACCESS TEST" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	try {
		Array<int> a(3);

		a[0] = 123;
		a[1] = 456;
		a[2] = 789;

		const Array<int> c(a);

		std::cout << "c: ";
		printArray(c);

		std::cout << "c[999] should throw: ";
		std::cout << c[999];
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test4() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "STRING ARRAY TEST" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	try {
		Array<std::string> a(3);

		a[0] = "Hello";
		a[1] = "World it's me!";
		a[2] = "Hihi haha";

		std::cout << "a before changes: ";
		printArray(a);

		Array<std::string> b(a);

		a[1] = "Ooga booga";

		std::cout << "a after changes: ";
		printArray(a);

		std::cout << "b: ";
		printArray(b);

		std::cout << "a[-3] should throw: ";
		std::cout << a[-3];
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test5() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "CHAR ARRAY TEST" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	try {
		Array<char> a(3);

		a[0] = 'a';
		a[1] = 'z';
		a[2] = '!';

		std::cout << "a before changes: ";
		printArray(a);

		Array<char> b(a);

		a[1] = 'G';

		std::cout << "a after changes: ";
		printArray(a);

		std::cout << "b: ";
		printArray(b);

		std::cout << "a[-111] should throw: ";
		std::cout << a[-111];
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
    std::cout << C_G << "END OF TESTS" << C_RST;
    std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
}
