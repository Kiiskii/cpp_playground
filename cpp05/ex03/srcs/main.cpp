#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

void test1() {
	std::cout << C_W << "\nBASIC SHRUBBERY FORM TESTS" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	try {
		Bureaucrat pres("President", 1);
		Intern intern;
		AForm *a;

		std::cout << pres << std::endl;

		a = intern.makeForm("shrubbery creation form", "tree");
		std::cout << *a << std::endl;
		pres.signForm(*a);
		pres.executeForm(*a);
		std::cout << *a << std::endl;
		delete a;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test2() {
	std::cout << C_W << "\nBASIC PRESIDENTIAL PARDON FORM TESTS" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	try {
		Bureaucrat vpres("Vice President", 1);
		Intern intern1;
		AForm *b;

		std::cout << vpres << std::endl;

		b = intern1.makeForm("presidential pardon form", "Pete");
		std::cout << *b << std::endl;
		vpres.signForm(*b);
		vpres.executeForm(*b);
		std::cout << *b << std::endl;
		delete b;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test3() {
	std::cout << C_W << "\nBASIC ROBOTOMY REQUEST FORM TESTS" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	try {
		Bureaucrat gov("Governer", 1);
		Intern intern2;
		AForm *c;

		std::cout << gov << std::endl;

		c = intern2.makeForm("robotomy request form", "Steve");
		std::cout << *c << std::endl;
		gov.signForm(*c);
		gov.executeForm(*c);
		std::cout << *c << std::endl;
		delete c;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test4() {
	std::cout << C_W << "\nINVALID FORM TESTS" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	try {
		Bureaucrat dude("Dude", 1);
		Intern intern3;
		AForm *d;

		std::cout << dude << std::endl;

		d = intern3.makeForm("invalid form", "Steve");
		std::cout << *d << std::endl;
		dude.signForm(*d);
		dude.executeForm(*d);
		std::cout << *d << std::endl;
		delete d;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test5() {
	std::cout << C_W << "\nCANNOT SIGN FORM TESTS" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	try {
		Bureaucrat dudette("Dudette", 149);
		Intern intern4;
		AForm *e;

		std::cout << dudette << std::endl;

		e = intern4.makeForm("presidential pardon form", "Steve");
		std::cout << *e << std::endl;
		dudette.signForm(*e);
		dudette.executeForm(*e);
		std::cout << *e << std::endl;
		delete e;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test6() {
	std::cout << C_W << "\nCANNOT EXECUTE FORM TESTS" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	try {
		Bureaucrat bruh("Bruh", 69);
		Intern intern5;
		AForm *f;

		std::cout << bruh << std::endl;

		f = intern5.makeForm("robotomy request form", "Paul");
		std::cout << *f << std::endl;
		bruh.signForm(*f);
		bruh.executeForm(*f);
		std::cout << *f << std::endl;
		delete f;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

int main() {
	srand(time(nullptr));
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
