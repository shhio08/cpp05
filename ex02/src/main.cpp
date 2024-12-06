#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Bureaucrat.hpp"

int main()
{
    try
    {
        // Bureaucrat の作成
        Bureaucrat bureaucrat("John Doe", 140);  // 署名グレードは 145 以下である必要がある

        // ShrubberyCreationForm の作成
        ShrubberyCreationForm form("home");

        // Bureaucrat によるフォームへの署名
        std::cout << "Attempting to sign form..." << std::endl;
        bureaucrat.signForm(form);

        // Bureaucrat によるフォームの実行
        std::cout << "Attempting to execute form..." << std::endl;
        bureaucrat.executeForm(form);
    }
    catch (const std::exception &e)
    {
        // 例外が発生した場合
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
