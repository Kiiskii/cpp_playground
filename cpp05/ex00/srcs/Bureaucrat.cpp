#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("noName"), _grade(150) {
	std::cout << C_C << "Bureaucrat default contructor called." << C_RST << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	std::cout << C_C << "Bureaucrat contructor called." << C_RST << std::endl;

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
	std::cout << C_C << "Copy constructor called." << C_RST << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << C_C << "Copy assignment operator called." << C_RST << std::endl;
	if (this != &other)
		_grade = other.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << C_C << "Bureaucrat destructor called." << C_RST << std::endl;
}

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
	_grade--;
	if (_grade < 1) {
		std::cout << "Bureaucrat " << _name << ": ";
		throw GradeTooHighException();
	}
}

void Bureaucrat::decrementGrade() {
	_grade++;
	if (_grade > 150) {
		std::cout << "Bureaucrat " << _name << ": ";
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bur) {
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return out;
}
