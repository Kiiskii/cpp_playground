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

void ShrubberyCreationForm::execute(Bureaucrat& exec) const {
	if (!getSigned())
		throw FormNotSignedException();
	if (exec.getExecGrade() > getExecGrade())
		throw GradeTooLowException();

	std::ofstream outfile(_target + "_shrubbery");
	if (!outfile.isopen())
		throw FileCreationError();
	outfile
	<<			"/\\\n"
	<<		   "/||\\\n"
	<< std::endl;

	outfile.close();
	std::cout << "Shrubbery created into " << _target + "_shrubbery" << std::endl;
}
