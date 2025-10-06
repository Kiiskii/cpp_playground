#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("noName"), _grade(150) {
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	if (grade < 1) {
		std::cout << "Bureaucrat " << _name << ": ";
		throw GradeTooHighException();
	}
	else if (grade > 150) {
		std::cout << "Bureaucrat " << _name << ": ";
		throw GradeTooLowException();
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()), _grade(other.getGrade()) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		_grade = other.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "grade too high. Must be greater than or equal to 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "grade too low. Must be less than or equal to 150.";
}

void Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1) {
		std::cout << "Bureaucrat " << _name << ": ";
		throw GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150) {
		std::cout << "Bureaucrat " << _name << ": ";
		throw GradeTooLowException();
	}
	_grade++;
}

void Bureaucrat::signForm(Form& f) {
	try {
		f.beSigned(*this);
		std::cout << C_G << "Bureaucrat " << getName() << " signed " << f.getName() << "." << C_RST << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << C_R << getName() << " could not sign " << f.getName() << ", " << e.what() << C_RST << std::endl;
	}
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bur) {
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return out;
}
