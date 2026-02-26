#include "../inc/MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>

#define C_R		"\033[0;31m\001"
#define C_G		"\033[0;32m\001"
#define C_RST	"\033[0m\002"

void test1() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "SUBJECT TEST" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void test2() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "SAME TEST WITH STD::LIST" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl;

	lst.pop_back();

	std::cout << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void test3() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "REVERSE ITERATOR TEST" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);

	std::cout << "forward:  ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "reverse:  ";
	for (MutantStack<int>::rev_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void test4() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "CONST ITERATOR TEST" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	MutantStack<int> mstack;
	mstack.push(10);
	mstack.push(20);
	mstack.push(30);

	const MutantStack<int> cstack(mstack);

	std::cout << "const forward:  ";
	for (MutantStack<int>::const_iterator it = cstack.begin(); it != cstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "const reverse:  ";
	for (MutantStack<int>::const_rev_iterator it = cstack.rbegin(); it != cstack.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void test5() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "STRING STACK TEST" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	MutantStack<std::string> mstack;
	mstack.push("Hello");
	mstack.push("World");
	mstack.push("42");

	std::cout << "top: " << mstack.top() << std::endl;

	for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void test6() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "COPY & ASSIGNMENT TEST" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	MutantStack<int> copy(mstack);
	MutantStack<int> assigned;
	assigned = mstack;

	mstack.push(999);

	std::cout << "original: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "copy (should not have 999): ";
	for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "assigned (should not have 999): ";
	for (MutantStack<int>::iterator it = assigned.begin(); it != assigned.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void test7() {
	std::cout << C_G << std::string(20, '=') << C_RST << std::endl;
	std::cout << C_G << "EMPTY STACK ITERATION" << C_RST;
	std::cout << C_G << "\n" << std::string(20, '=') << C_RST << std::endl;

	MutantStack<int> mstack;

	std::cout << "iterating empty stack (should print nothing): ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "empty: " << mstack.empty() << " (expected 1)" << std::endl;
	std::cout << "size: " << mstack.size() << " (expected 0)" << std::endl;
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
