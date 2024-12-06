#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

	const std::string &getName() const;
	int getGrade() const;

// increment and decrement grade
	void incrementGrade();
	void decrementGrade();

// exception classes
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

	void signForm(class Form &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);