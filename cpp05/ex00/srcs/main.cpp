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
	try {
		Bureaucrat ("Dimo", -1);
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test2() {
	std::cout << C_W << "\nBASIC TEST" << std::endl;
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
	Bureaucrat himo("Himo", 75);
	try {
		std::cout << C_G << himo << " before." << C_RST <<std::endl;
		for (int i = 0; i < 8; i++)
			himo.incrementGrade();
		std::cout << C_G << himo << " after." << C_RST << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
	Bureaucrat hhimo(himo);
	try {
		std::cout << C_G << hhimo << " before." << C_RST <<std::endl;
		for (int i = 0; i < 66; i++)
			hhimo.incrementGrade();
		std::cout << C_G << hhimo << " after." << C_RST << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test4() {
	std::cout << C_W << "\nDECREMENT TEST" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	Bureaucrat limo("Limo", 75);
	try {
		std::cout << C_G << limo << " before." << C_RST <<std::endl;
		for (int i = 0; i < 6; i++)
			limo.decrementGrade();
		std::cout << C_G << limo << " after." << C_RST << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
	Bureaucrat llimo;
	llimo = limo;
	try {
		std::cout << C_G << llimo << " before." << C_RST <<std::endl;
		for (int i = 0; i < 69; i++)
			llimo.decrementGrade();
		std::cout << C_G << llimo << " after." << C_RST << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test5() {
	std::cout << C_W << "\nINCREMENT ERROR TEST" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	Bureaucrat pimo("Pimo", 5);
	try {
		std::cout << C_G << pimo << " before." << C_RST <<std::endl;
		for (int i = 0; i < 8; i++)
			pimo.incrementGrade();
		std::cout << C_G << pimo << " after." << C_RST << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
	std::cout << C_G << pimo << " after." << C_RST << std::endl;
}

void test6() {
	std::cout << C_W << "\nDECREMENT ERROR TEST" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	Bureaucrat mimo("Mimo", 147);
	try {
		std::cout << C_G << mimo << " before." << C_RST <<std::endl;
		for (int i = 0; i < 6; i++)
			mimo.decrementGrade();
		std::cout << C_G << mimo << " after." << C_RST << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
	std::cout << C_G << mimo << " after." << C_RST << std::endl;
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();

	std::cout << C_W << "\n===============================" << std::endl;
	std::cout << "END TESTS" << C_RST << std::endl;
	return 0;
}
