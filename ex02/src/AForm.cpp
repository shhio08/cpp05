#include "../inc/AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _signGrade(1), _execGrade(1) {}

AForm::AForm(const std::string &name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return *this;
	_signed = other._signed;
	return *this;
}

const std::string &AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << form.getName() << " form is " << (form.getSigned() ? "signed" : "not signed") << " and requires grade " << form.getSignGrade() << " to sign and grade " << form.getExecGrade() << " to execute.";
	return out;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!getSigned())
		throw std::runtime_error("Error: form is not signed");
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
}