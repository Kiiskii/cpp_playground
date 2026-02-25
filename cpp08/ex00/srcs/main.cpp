#include "../inc/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <exception>

#define C_R		"\033[0;31m\001"
#define C_G		"\033[0;32m\001"
#define C_RST	"\033[0m\002"

void test1() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "VECTOR: FIND EXISTING VALUE" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	try {
		std::vector<int> v = {10, 20, 30, 40, 50};

		std::cout << "searching for 30 in {10, 20, 30, 40, 50}" << std::endl;
		std::cout << "found: " << *easyFind(v, 30) << std::endl;

		std::cout << "searching for 10 (first element)" << std::endl;
		std::cout << "found: " << *easyFind(v, 10) << std::endl;

		std::cout << "searching for 50 (last element)" << std::endl;
		std::cout << "found: " << *easyFind(v, 50) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << "exception: " << e.what() << C_RST << std::endl;
	}
}

void test2() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "VECTOR: VALUE NOT FOUND" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	try {
		std::vector<int> v = {10, 20, 30};

		std::cout << "searching for 99 in {10, 20, 30}" << std::endl;
		std::cout << "found: " << *easyFind(v, 99) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << "exception: " << e.what() << C_RST << std::endl;
	}
}

void test3() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "LIST: FIND EXISTING VALUE" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	try {
		std::list<int> lst = {5, 15, 25, 35};

		std::cout << "searching for 25 in {5, 15, 25, 35}" << std::endl;
		std::cout << "found: " << *easyFind(lst, 25) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << "exception: " << e.what() << C_RST << std::endl;
	}
}

void test4() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "LIST: VALUE NOT FOUND" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	try {
		std::list<int> lst = {5, 15, 25};

		std::cout << "searching for 100 in {5, 15, 25}" << std::endl;
		std::cout << "found: " << *easyFind(lst, 100) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << "exception: " << e.what() << C_RST << std::endl;
	}
}

void test5() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "DEQUE: FIND EXISTING VALUE" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	try {
		std::deque<int> dq = {42, 84, 126};

		std::cout << "searching for 84 in {42, 84, 126}" << std::endl;
		std::cout << "found: " << *easyFind(dq, 84) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << "exception: " << e.what() << C_RST << std::endl;
	}
}

void test6() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "EMPTY CONTAINER" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	try {
		std::vector<int> v;

		std::cout << "searching for 1 in empty vector" << std::endl;
		std::cout << "found: " << *easyFind(v, 1) << std::endl;
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
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "END OF TESTS" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;
}
