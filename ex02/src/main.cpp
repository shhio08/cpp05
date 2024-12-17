#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main()
{
    try
    {
        // Bureaucrat の作成
        Bureaucrat b1("test", 140);  // 署名グレードは 145 以下である必要がある
        Bureaucrat b2("test2", 135);  // 署名グレードは 145 以下である必要がある

        // ShrubberyCreationForm の作成
        ShrubberyCreationForm form("home");

        // Bureaucrat によるフォームへの署名
        std::cout << "Attempting to sign form..." << std::endl;
        b1.signForm(form);

        // b1 によるフォームの実行(グレードが足りないため例外が発生する)
        std::cout << "Attempting to execute form with b1..." << std::endl;
        b1.executeForm(form);

		// b2 によるフォームの実行(グレードが足りており成功する)
        std::cout << "Attempting to execute form with b2..." << std::endl;
        b2.executeForm(form);
    }
    catch (const std::exception &e)
    {
        // 例外が発生した場合
        std::cerr << "Exception: " << e.what() << std::endl;
    }

	std::cout << "-------------------------------------" << std::endl;

	srand(time(NULL));
	try
	{
        // Bureaucrat の作成
        Bureaucrat b3("test3", 70);  // 署名グレードは 72 以下である必要がある
        Bureaucrat b4("test4", 40);  // 実行グレードは 45 以下である必要がある

        // RobotomyRequestForm の作成
        RobotomyRequestForm robotomyForm("test_robot");

        // Bureaucrat によるフォームへの署名
        std::cout << "Attempting to sign RobotomyRequestForm..." << std::endl;
        b3.signForm(robotomyForm);

        // b3 によるフォームの実行(グレードが足りないため例外が発生する)
        std::cout << "Attempting to execute RobotomyRequestForm with b3..." << std::endl;
        b3.executeForm(robotomyForm);

        // b4 によるフォームの実行(グレードが足りており成功する)
        std::cout << "Attempting to execute RobotomyRequestForm with b4..." << std::endl;
        b4.executeForm(robotomyForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exeption: " << e.what() << '\n';
	}

	std::cout << "-------------------------------------" << std::endl;

    try
    {
        // Bureaucrat の作成
        Bureaucrat b5("test5", 20);  // 署名グレードは 25 以下である必要がある
        Bureaucrat b6("test6", 5);   // 実行グレードは 5 以下である必要がある

        // PresidentialPardonForm の作成
        PresidentialPardonForm presidentialForm("test_target");

        // Bureaucrat によるフォームへの署名
        std::cout << "Attempting to sign PresidentialPardonForm..." << std::endl;
        b5.signForm(presidentialForm);

        // b5 によるフォームの実行(グレードが足りないため例外が発生する)
        std::cout << "Attempting to execute PresidentialPardonForm with b5..." << std::endl;
        b5.executeForm(presidentialForm);

        // b6 によるフォームの実行(グレードが足りており成功する)
        std::cout << "Attempting to execute PresidentialPardonForm with b6..." << std::endl;
        b6.executeForm(presidentialForm);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    return 0;
}
