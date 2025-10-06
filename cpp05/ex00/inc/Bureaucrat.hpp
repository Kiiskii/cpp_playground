#pragma once

#include <iostream>
#include <string>

#define C_R		"\033[0;31m\001"
#define C_RST	"\033[0m\002"
#define C_G		"\033[0;32m\001"
#define C_W		"\033[0;37m\001"
#define C_C		"\033[0;36m\001"

class Bureaucrat {
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat() = delete;
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other) = delete;
	~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bur);
