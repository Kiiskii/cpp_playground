#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
AForm("RobotomyRequestForm", 72, 45) {
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
AForm(other) {
	_target = other._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	AForm::operator=(other);
	if (this != &other) {
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& exec) const {
	if (!getSigned())
		throw FormNotSignedException();
	if (exec.getGrade() > getExecGrade())
		throw GradeTooLowException();

	if (rand() % 2 == 0)
		std::cout << C_G << _target << " has been robotomized successfully!" << C_RST << std::endl;
	else
		std::cout << C_Y << _target << " robotomy has failed." << C_RST << std::endl;
}
