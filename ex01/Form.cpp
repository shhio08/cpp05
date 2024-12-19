#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _signGrade(1), _execGrade(1) {}

Form::Form(const std::string &name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

Form &Form::operator=(const Form &other)
{
	if (this == &other)
		return *this;
	_signed = other._signed;
	return *this;
}

const std::string &Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecGrade() const
{
	return _execGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << " form is " << (form.getSigned() ? "signed" : "not signed") << " and requires grade " << form.getSignGrade() << " to sign and grade " << form.getExecGrade() << " to execute.";
	return out;
}