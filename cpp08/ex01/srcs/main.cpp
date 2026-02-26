#include "../inc/Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <exception>

#define C_R		"\033[0;31m\001"
#define C_G		"\033[0;32m\001"
#define C_RST	"\033[0m\002"

void test1() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "SUBJECT TEST" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	try {
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "shortestSpan: " << sp.shortestSpan() << " (expected 2)" << std::endl;
		std::cout << "longestSpan: " << sp.longestSpan() << " (expected 14)" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << "exception: " << e.what() << C_RST << std::endl;
	}
}

void test2() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "OVERFLOW: ADD TO FULL SPAN" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	try {
		Span sp(3);

		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);

		std::cout << "adding 4th element to Span(3), should throw:" << std::endl;
		sp.addNumber(4);
	}
	catch (const std::exception& e) {
		std::cout << C_R << "exception: " << e.what() << C_RST << std::endl;
	}
}

void test3() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "TOO FEW ELEMENTS FOR SPAN" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	try {
		Span sp(5);

		std::cout << "shortestSpan on empty Span, should throw:" << std::endl;
		sp.shortestSpan();
	}
	catch (const std::exception& e) {
		std::cout << C_R << "exception: " << e.what() << C_RST << std::endl;
	}

	try {
		Span sp(5);
		sp.addNumber(42);

		std::cout << "longestSpan on single element, should throw:" << std::endl;
		sp.longestSpan();
	}
	catch (const std::exception& e) {
		std::cout << C_R << "exception: " << e.what() << C_RST << std::endl;
	}
}

void test4() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "RANGE ADD WITH ITERATORS" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	try {
		std::vector<int> v = {100, 200, 300, 400, 500};
		Span sp(5);

		sp.addNumber(v.begin(), v.end());

		std::cout << "shortestSpan: " << sp.shortestSpan() << " (expected 100)" << std::endl;
		std::cout << "longestSpan: " << sp.longestSpan() << " (expected 400)" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << "exception: " << e.what() << C_RST << std::endl;
	}
}

void test5() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "RANGE ADD OVERFLOW" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	try {
		std::list<int> lst = {1, 2, 3, 4, 5};
		Span sp(3);

		std::cout << "adding 5 elements to Span(3) via range, should throw:" << std::endl;
		sp.addNumber(lst.begin(), lst.end());
	}
	catch (const std::exception& e) {
		std::cout << C_R << "exception: " << e.what() << C_RST << std::endl;
	}
}

void test6() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "10,000 ELEMENTS TEST" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	try {
		Span sp(10000);

		//std::srand(42);
		std::srand(std::time(NULL));
		for (int i = 0; i < 10000; i++)
			sp.addNumber(std::rand());

		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << "exception: " << e.what() << C_RST << std::endl;
	}
}

void test7() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "COPY CONSTRUCTOR TEST" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	try {
		Span sp(5);
		sp.addNumber(1);
		sp.addNumber(10);
		sp.addNumber(100);

		Span copy(sp);

		std::cout << "original shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "copy shortestSpan: " << copy.shortestSpan() << std::endl;
		std::cout << "original longestSpan: " << sp.longestSpan() << std::endl;
		std::cout << "copy longestSpan: " << copy.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << "exception: " << e.what() << C_RST << std::endl;
	}
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "END OF TESTS" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
}
