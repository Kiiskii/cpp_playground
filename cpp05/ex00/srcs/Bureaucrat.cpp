#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("noName"), _grade(150) {
	std::cout << "Bureaucrat default contructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	std::cout << "Bureaucrat contructor called." << std::endl;

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

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()), _grade(other.getGrade()) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		_grade = other.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called." << std::endl;
}

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "grade too high. Must be 1 or greater than 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "grade too low. Must be 150 or less than 1.";
}

void Bureaucrat::incrementGrade() {
	_grade--;
}

void Bureaucrat::decrementGrade() {
	_grade++;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bur) {
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return out;
}
