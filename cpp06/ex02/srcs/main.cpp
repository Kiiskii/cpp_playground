#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base* generate() {
	Base* ptr = nullptr;

	std::srand(time(0));
	int randomValue = (std::rand() % 100) % 3;
	switch (randomValue) {
		case 0:
			ptr = new A();
			break ;
		case 1:
			ptr = new B();
			break ;
		case 2:
			ptr = new C();
			break ;
		default:
			break ;
	}
	return ptr;
}
