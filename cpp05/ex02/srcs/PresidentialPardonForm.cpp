#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
AForm("PresidentialPardonForm", 25, 5) {
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
AForm(other) {
	_target = other._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	AForm::operator=(other);
	if (this != &other) {
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& exec) const {
	if (!getSigned())
		throw FormNotSignedException();
	if (exec.getGrade() > getExecGrade())
		throw GradeTooLowException();

	std::cout << C_C << _target << " has been pardoned by Zaphod Beeblebrox." << C_RST << std::endl;
}
