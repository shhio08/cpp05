#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include <stdlib.h>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;

public:
	AForm();
	AForm(const std::string &name, int signGrade, int execGrade);
	~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);

	const std::string &getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	virtual void execute(const Bureaucrat &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);
