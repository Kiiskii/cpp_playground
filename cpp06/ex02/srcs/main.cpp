#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

#define C_G		"\033[0;32m\001"
#define C_R		"\033[0;31m\001"
#define C_RST	"\033[0m\002"

Base* generate() {
	switch (std::rand() % 3) {
		case 0: 
			return new A();
		case 1: 
			return new B();
		default: 
			return new C();
	}
}

void identify(Base* p) {
	if (!p)
		std::cout << "nullptr" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "A" << C_RST << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << C_RST << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << C_RST << std::endl;
	else
		std::cout << C_R << "Unknown" << C_RST << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << C_RST << std::endl;
		return ;
	}
	catch (...) {
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << C_RST << std::endl;
		return ;
	}
	catch (...) {
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << C_RST << std::endl;
		return ;
	}
	catch (...) {
	}
	std::cout << C_R << "Unknown" << C_RST << std::endl;
}

int main() {
	std::srand(std::time(0));

	int countA = 0, countB = 0, countC = 0;

	for (int i = 0; i < 10; i++) {
		Base* b = generate();

		std::cout << C_G << "pointer is: ";
		identify(b);

		if (b) {
			std::cout << C_G << "reference is: ";
			identify(*b);
		}

		if (dynamic_cast<A*>(b))
			countA++;
		else if (dynamic_cast<B*>(b))
			countB++;
		else if (dynamic_cast<C*>(b))
			countC++;

		delete b;

		std::cout << std::endl;
	}

	std::cout << C_G << "Totals -> A: " << countA << ", B: " << countB << ", C: " << countC << C_RST << std::endl;
}
