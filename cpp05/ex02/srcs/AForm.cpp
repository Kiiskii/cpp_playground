#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec) :
	_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (gradeToSign < 1 || gradeToExec < 1) {
		std::cout << "AForm: ";
		throw GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExec > 150) {
		std::cout << "AForm: ";
		throw GradeTooLowException();
	}
}

AForm::AForm(const AForm& other) :
	_name(other.getName()), _signed(other.getSigned()),
	_gradeToSign(other.getSignGrade()), _gradeToExec(other.getExecGrade()) {
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		_signed = other.getSigned();
	return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getSignGrade() const {
	return _gradeToSign;
}

int AForm::getExecGrade() const {
	return _gradeToExec;
}

void AForm::beSigned(const Bureaucrat& bur) {
	if (bur.getGrade() > getSignGrade())
		throw GradeTooLowException();
	if (getSigned())
		throw AlreadySignedException();
	_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "grade too high.";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "grade too low.";
}

const char* AForm::AlreadySignedException::what() const throw() {
	return "form is already signed.";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "form is not signed.";
}

std::ostream& operator<<(std::ostream &out, const AForm& f) {
	out << "\nAForm name: " << f.getName() << "\nIs signed: ";
	if (f.getSigned())
		out << "Yes.";
	else
		out << "No.";
	out << "\nMinimum grade to sign: " << f.getSignGrade() << "\nMinimum grade to execute: " << f.getExecGrade() << "\n";
	return out;
}
