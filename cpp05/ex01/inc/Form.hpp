#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExec;
public:
	Form() = delete;
	Form(const std::string& name, int gradeToSign, int gradeToExec);
	Form(const Form& other);
	Form& operator=(const Form& other) = delete;
	~Form();

	const std::string& getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(const Bureaucrat& bur);

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	class AlreadySignedException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &out, const Form& f);
