#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main()
{
    Intern intern;

    AForm *shrubbery = intern.makeForm("ShrubberyCreation", "home");
    if (shrubbery)
    {
        std::cout << "\033[32m" << *shrubbery << "\033[0m" << std::endl;
        delete shrubbery;
    }
    else
    {
        std::cout << "\033[31m" << "Failed to create ShrubberyCreationForm object." << "\033[0m" << std::endl;
    }

    AForm *robotomy = intern.makeForm("RobotomyRequest", "home");
    if (robotomy)
    {
        std::cout << "\033[32m" << *robotomy << "\033[0m" << std::endl;
        delete robotomy;
    }
    else
    {
        std::cout << "\033[31m" << "Failed to create RobotomyRequestForm object." << "\033[0m" << std::endl;
    }

    AForm *presidential = intern.makeForm("PresidentialPardon", "home");
    if (presidential)
    {
        std::cout << "\033[32m" << *presidential << "\033[0m" << std::endl;
        delete presidential;
    }
    else
    {
        std::cout << "\033[31m" << "Failed to create PresidentialPardonForm object." << "\033[0m" << std::endl;
    }

    AForm *invalid = intern.makeForm("InvalidForm", "home");
    if (invalid)
    {
        std::cout << "\033[32m" << *invalid << "\033[0m" << std::endl;
        delete invalid;
    }
    else
    {
        std::cout << "\033[31m" << "Failed to create InvalidForm object." << "\033[0m" << std::endl;
    }

    return 0;
}

// __attribute__((destructor)) static void destructor ()
// {
// 	system("leaks -q Intern");
// }