#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : 
AForm("ShrubberyCreationForm", 145, 137) {
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
AForm(other) {
	_target = other._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	AForm::operator=(other);
	if (this != &other) {
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char* ShrubberyCreationForm::FileCreationError::what() const throw() {
	return "Error: Could not open file for writing.";
}

void ShrubberyCreationForm::execute(const Bureaucrat& exec) const {
	if (!getSigned())
		throw FormNotSignedException();
	if (exec.getGrade() > getExecGrade())
		throw GradeTooLowException();

	std::ofstream outfile(_target + "_shrubbery");
	if (!outfile.is_open())
		throw FileCreationError();
	outfile
	<< "             /&\\\n"
	<< "            /&&&\\\n"
	<< "           /&&&&&\\\n"
	<< "          /&&&&&&&\\\n"
	<< "         /&&&&&&&&&\\\n"
	<< "        /&&&&&&&&&&&\\\n"
	<< "       /&&&&&&&&&&&&&\\\n"
	<< "      /&&&&&&&&&&&&&&&\\\n"
	<< "     /&&&&&&&&&&&&&&&&&\\\n"
	<< "    /&&&&&&&&&&&&&&&&&&&\\\n"
	<< "           |||||||\n"
	<< "           |||||||\n"
	<< "           |||||||\n"
	<< "           |||||||\n"
	<< "           |||||||\n"
	<< "       ================\n"
	<< "       ================\n"
	<< std::endl;

	outfile.close();
	std::cout << C_C << "Shrubbery created into " << _target + "_shrubbery" << C_RST << std::endl;
}
