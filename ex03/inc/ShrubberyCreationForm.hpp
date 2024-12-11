#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
	ShrubberyCreationForm();

public:
	ShrubberyCreationForm(const std::string &other);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	void execute(const Bureaucrat &executor) const;
};