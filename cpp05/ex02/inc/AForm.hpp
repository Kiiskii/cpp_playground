#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExec;
public:
	AForm() = delete;
	AForm(const std::string& name, int gradeToSign, int gradeToExec);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other) = delete;
	virtual ~AForm();

	const std::string& getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(const Bureaucrat& bur);
	virtual void execute(const Bureaucrat& exec) const = 0;

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

	class ForNotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &out, const AForm& f);
