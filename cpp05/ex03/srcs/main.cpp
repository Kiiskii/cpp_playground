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

		a = intern.makeForm("presidential pardon form", "Pete");
		std::cout << *a << std::endl;
		pres.signForm(*a);
		pres.executeForm(*a);
		std::cout << *a << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << e.what() << C_RST << std::endl;
	}
}

int main() {
	srand(time(nullptr));
	test1();

	std::cout << C_W << "\n===============================" << std::endl;
	std::cout << "END TESTS" << C_RST << std::endl;
	return 0;
}
