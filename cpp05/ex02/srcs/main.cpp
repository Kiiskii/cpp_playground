#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

void test1() {
	std::cout << C_W << "\nBASIC SHRUBBERY FORM TESTS" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	try {
		Bureaucrat pres("President", 1);
		std::cout << pres << std::endl;

		ShrubberyCreationForm s("tree");
		pres.signForm(s);
		pres.executeForm(s);
		std::cout << s << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
	try {
		Bureaucrat mana("Manager", 139);
		std::cout << mana << std::endl;

		ShrubberyCreationForm ss("trees");
		mana.signForm(ss);
		mana.executeForm(ss);
		std::cout << ss << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test2() {
	std::cout << C_W << "\nBASIC PRESIDENTIAL PARDON FORM TESTS" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	try {
		Bureaucrat pres("President", 1);
		std::cout << pres << std::endl;

		PresidentialPardonForm s("You");
		pres.signForm(s);
		pres.executeForm(s);
		std::cout << s << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
	try {
		Bureaucrat mana("Manager", 21);
		std::cout << mana << std::endl;

		PresidentialPardonForm ss("trees");
		mana.signForm(ss);
		mana.executeForm(ss);
		std::cout << ss << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

void test3() {
	std::cout << C_W << "\nBASIC ROBOTOMY REQUEST FORM TESTS" << std::endl;
	std::cout << "===============================" << C_RST << std::endl;
	try {
		Bureaucrat pres("President", 1);
		std::cout << pres << std::endl;

		RobotomyRequestForm s("Pete");
		pres.signForm(s);
		pres.executeForm(s);
		std::cout << s << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
	try {
		Bureaucrat mana("Manager", 69);
		std::cout << mana << std::endl;

		RobotomyRequestForm ss("Luke");
		mana.signForm(ss);
		mana.executeForm(ss);
		std::cout << ss << std::endl;
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

	std::cout << C_W << "\n===============================" << std::endl;
	std::cout << "END TESTS" << C_RST << std::endl;
	return 0;
}
