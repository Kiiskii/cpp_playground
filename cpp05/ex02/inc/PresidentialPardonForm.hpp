#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string _target;
public:
	PresidentialPardonForm() = delete;
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	void execute(const Bureaucrat& exec) const override;
};
