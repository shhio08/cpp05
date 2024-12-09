#pragma once

#include "AForm.hpp"
#include <map>

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);

	AForm *makeForm(const std::string &formName, const std::string &target);
	AForm *createShrubberyCreationForm(const std::string &target);
	AForm *createRobotomyRequestForm(const std::string &target);
	AForm *createPresidentialPardonForm(const std::string &target);
};