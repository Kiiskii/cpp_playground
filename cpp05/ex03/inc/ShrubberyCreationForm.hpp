#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string _target;
public:
	ShrubberyCreationForm() = delete;
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	void execute(const Bureaucrat& exec) const override;

	class FileCreationError : public std::exception {
	public:
		const char* what() const throw();
	};
};
