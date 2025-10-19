#include "iter.hpp"
#include <iostream>
#include <string>

#define C_G		"\033[0;32m\001"
# define C_RST	"\033[0m\002"

template <typename T>
void print(T& printable) {
	std::cout << printable;
}

template <typename T>
void increment(T& inc) {
	inc++;
}

void toUpCase(char c) {
	char upCase = std::toupper(c);
	std::cout << upCase;
}

void printPtr(int *ptr) {
	std::cout << "Pointer address: " << ptr << std::endl;
	std::cout << "Value: " << *ptr << std::endl;
}

void test1() {
	int array[] = {-1 ,0, 1, 2 ,3};
	std::cout << "Array before: ";
	::iter(array, 5, print<int>);
	std::cout << "\n";
	std::cout << "Array after: ";
	::iter(array, 5, increment<int>);
	::iter(array, 5, print<int>);
	std::cout << "\n";
}

void test2() {
	char array[] = {'a' ,'b', 'c', 'd' ,'e'};
	std::cout << "Array before: ";
	::iter(array, 5, print<char>);
	std::cout << "\n";
	std::cout << "Array after: ";
	::iter(array, 5, increment<char>);
	::iter(array, 5, print<char>);
	std::cout << "\n";
}

void test3() {
	char array[] = {'a' ,'b', 'c', 'd' ,'e', ' ', '!'};
	std::cout << "Array before: ";
	::iter(array, 7, print<char>);
	std::cout << "\n";
	std::cout << "Array after: ";
	::iter(array, 7, toUpCase);
	std::cout << "\n";
}

void test4() {
	int a = 3;
	int b = 6;
	int c = 10;
	int* arr[] = {&a, &b, &c};

	::iter(arr, 3, printPtr);

	std::string* nullPtr = nullptr;

	std::cout << "Null pointer: ";
	::iter(nullPtr, 9, print<std::string>);
	std::cout << "\n";
}

void test5() {
	int intArray[] = {-1 ,0, 1, 2 ,3};
	std::cout << "Print int array: ";
	::iter(intArray, 3, print<int>);
	std::cout << "\n";

	char charArray[] = {'a' ,'b', 'c', 'd' ,'e'};
	std::cout << "Print char array: ";
	::iter(charArray, 2, print<char>);
	std::cout << "\n";
}

void test6() {
	const std::string arr[] = {"Hello", "It's a", "Me", "Mario"};
	::iter(arr, 4, print<const std::string>);
	std::cout << "\n";
}

int main() {
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
	std::cout << "TEST INT INCREMENT" << std::endl;
	std::cout << C_G << std::string(20, '=') << "\n" << C_RST << std::endl;
	test1();
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
	std::cout << "TEST CHAR INCREMENT" << std::endl;
	std::cout << C_G << std::string(20, '=') << "\n" << C_RST << std::endl;
	test2();
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
	std::cout << "TEST CHAR TOUPPER" << std::endl;
	std::cout << C_G << std::string(20, '=') << "\n" << C_RST << std::endl;
	test3();
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
	std::cout << "TEST INT POINTERS & NULL" << std::endl;
	std::cout << C_G << std::string(20, '=') << "\n" << C_RST << std::endl;
	test4();
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
	std::cout << "TEST INCORRECT ARRAY SIZES" << std::endl;
	std::cout << C_G << std::string(20, '=') << "\n" << C_RST << std::endl;
	test5();
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
	std::cout << "TEST CONST STRINGS" << std::endl;
	std::cout << C_G << std::string(20, '=') << "\n" << C_RST << std::endl;
	test6();
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
	std::cout << "END TESTS" << std::endl;
	std::cout << C_G << std::string(20, '=') << "\n" << C_RST << std::endl;
	return 0;
}
