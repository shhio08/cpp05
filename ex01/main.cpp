#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("shiho", 1);
		std::cout << b1 << std::endl;

		Form f1("form1", 1, 1);
		std::cout << f1 << std::endl;

		b1.signForm(f1);

		std::cout << f1 << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	try
	{
		Bureaucrat b2("shiho", 150);
		std::cout << b2 << std::endl;

		Form f2("form2", 10, 10);
		std::cout << f2 << std::endl;

		b2.signForm(f2);

		std::cout << f2 << std::endl << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	try
	{
		Form f3("form3", 151, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	

	return 0;
}
