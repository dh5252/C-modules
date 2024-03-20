
#include "includes/Bureaucrat.hpp"

int main()
{
    {
        std::cout << "\nConstructor Test" << std::endl;
        try {
            Bureaucrat A("A", 0);
            std::cout << "A is created" << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << "\n";
        }
        try {
            Bureaucrat B("B", 1);
            std::cout << "B is created" << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << "\n";
        }
    }
    {
        std::cout << "\nModify Fail Test" << std::endl;
        Bureaucrat A("A", 2);
        Bureaucrat B("B", 149);

        try {
            A.incrementGrade(2);
            std::cout << "success!" << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << "\n";
        }

        try {
            B.decrementGrade(2);
            std::cout << "success!" << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << "\n";
        }
    }

    {
        std::cout << "\nModify Success Test" << std::endl;
        Bureaucrat A("A", 2);
        Bureaucrat B("B", 149);

        try {
            A.decrementGrade(2);
            std::cout << "success!" << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << "\n";
        }

        try {
            B.incrementGrade(2);
            std::cout << "success!" << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << "\n";
        }
    }
}