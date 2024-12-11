#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
	RobotomyRequestForm();

public:
	RobotomyRequestForm(const std::string &other);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	void execute(const Bureaucrat &executor) const;
};