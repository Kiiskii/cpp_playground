#include "Bureaucrat.hpp"

void test1() {
	std::cout << C_W << "\nBASIC FAIL TEST" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	try {
		Bureaucrat ("Timo", 151);
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test2() {
	std::cout << C_W << "\nBASIC FAIL TEST" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	try {
		Bureaucrat simo("Simo", 75);
		std::cout << C_G << simo << C_RST << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test3() {
	std::cout << C_W << "\nINCREMENT TEST" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	try {
		Bureaucrat himo("Himo", 75);
		std::cout << C_G << himo << " before." << C_RST <<std::endl;
		for (int i = 0; i < 8; i++)
			himo.incrementGrade();
		std::cout << C_G << himo << " after." << C_RST << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test4() {
	std::cout << C_W << "\nDECREMENT TEST" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	try {
		Bureaucrat limo("Limo", 75);
		std::cout << C_G << limo << " before." << C_RST <<std::endl;
		for (int i = 0; i < 6; i++)
			limo.decrementGrade();
		std::cout << C_G << limo << " after." << C_RST << std::endl;
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

	std::cout << C_W << "\n===============================" << std::endl;
	std::cout << "END TESTS" << C_RST << std::endl;
	return 0;
}
