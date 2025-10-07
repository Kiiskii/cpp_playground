#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
	_forms[0] = "presidential pardon form";
	_forms[1] = "robotomy request form";
	_forms[2] = "shrubbery creation form";
	functions[0] = &Intern::createPPF;
	functions[1] = &Intern::createRRF;
	functions[2] = &Intern::createSCF;
}

AForm* Intern::createPPF(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::createRRF(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createSCF(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

const char* Intern::FormDoesNotExistException::what() const throw() {
	return "Form does not exist.";
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
	for (int i = 0; i < 3; i++) {
		if (name == _forms[i]) {
			std::cout << C_G << "Intern creates " << _forms[i] << "." << C_RST << std::endl;
			return (this->*functions[i])(target);
		}
	}
	throw FormDoesNotExistException();
}
