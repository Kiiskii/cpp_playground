#pragma once

#include "AForm.hpp"

class Intern {
private:
	std::string _forms[3];
	AForm* (Intern::*functions[3])(const std::string& target);
public:
	Intern();
	Intern(const Intern& other) = delete;
	Intern& operator=(const Intern& other) = delete;
	~Intern() = default;

	AForm* createPPF(const std::string& target);
	AForm* createRRF(const std::string& target);
	AForm* createSCF(const std::string& target);

	AForm* makeForm(const std::string& name, const std::string& target);

	class FormDoesNotExistException : public std::exception {
	public:
		const char* what() const throw();
	};
};
