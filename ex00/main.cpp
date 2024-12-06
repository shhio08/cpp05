#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat1("shiho", 150);
		std::cout << bureaucrat1 << std::endl;

		bureaucrat1.incrementGrade();
		std::cout << bureaucrat1 << std::endl;

		bureaucrat1.decrementGrade();
		std::cout << bureaucrat1 << std::endl;

		bureaucrat1.decrementGrade();

	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat2("takimo", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat3("namae3", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}