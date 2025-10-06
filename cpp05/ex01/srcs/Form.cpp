#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExec) :
	_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (gradeToSign < 1 || gradeToExec < 1) {
		std::cout << "Form: ";
		throw GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExec > 150) {
		std::cout << "Form: ";
		throw GradeTooLowException();
	}
}

Form::Form(const Form& other) :
	_name(other.getName()), _signed(other.getSigned()),
	_gradeToSign(other.getSignGrade()), _gradeToExec(other.getExecGrade()) {
}

Form::~Form() {}

const std::string& Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getSignGrade() const {
	return _gradeToSign;
}

int Form::getExecGrade() const {
	return _gradeToExec;
}

void Form::beSigned(const Bureaucrat& bur) {
	if (bur.getGrade() > getSignGrade())
		throw GradeTooLowException();
	if (getSigned())
		throw AlreadySignedException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "grade too high.";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "grade too low.";
}

const char* Form::AlreadySignedException::what() const throw() {
	return "form is already signed.";
}

std::ostream& operator<<(std::ostream &out, const Form& f) {
	out << "\nForm name: " << f.getName() << "\nIs signed: ";
	if (f.getSigned())
		out << "Yes.";
	else
		out << "No.";
	out << "\nMinimum grade to sign: " << f.getSignGrade() << "\nMinimum grade to execute: " << f.getExecGrade() << "\n";
	return out;
}
