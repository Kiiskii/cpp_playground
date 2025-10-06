#include "Bureaucrat.hpp"
#include "Form.hpp"

void test1() {
	std::cout << C_W << "\nBASIC TESTS" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	try {
		Bureaucrat timo("Timo", 72);
		Form a("A21212", 110, 90);
		std::cout << timo << std::endl;
		timo.signForm(a);
		std::cout << a << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test2() {
	std::cout << C_W << "\nINCREMENT UNTIL SUCCESS TESTS" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	try {
		Bureaucrat simo("Simo", 90);
		Form b("B232323", 85, 50);
		std::cout << simo << std::endl;
		simo.signForm(b);
		std::cout << b << std::endl;
		for (int i = 0; i < 6; i++) {
			simo.incrementGrade();
			simo.signForm(b);
		}
		std::cout << b << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test3() {
	std::cout << C_W << "\nFORM LIMIT TESTS" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	try {
		Form c("C4545454", -1, 40);
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
	try {
		Form d("D4545454", 151, 40);
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test4() {
	std::cout << C_W << "\nCOPY CONSTRUCTOR TESTS" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	try {
		Form e("E123123", 30, 21);
		std::cout << e << std::endl;
		Form f(e);
		std::cout << f << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test5() {
	std::cout << C_W << "\nDECREMENT UNTIL CAN'T SIGN TESTS" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	try {
		Bureaucrat bimo("Bimo", 84);
		Form g("G232323", 85, 50);
		std::cout << bimo << std::endl;
		bimo.signForm(g);
		std::cout << g << std::endl;
		for (int i = 0; i < 3; i++) {
			bimo.decrementGrade();
			bimo.signForm(g);
		}
		std::cout << g << std::endl;
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

	std::cout << C_W << "\n===============================" << std::endl;
	std::cout << "END TESTS" << C_RST << std::endl;
	return 0;
}
