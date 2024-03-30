
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"

int main()
{
    {
        std::cout << "\nIntegrated Test" << std::endl;

        Bureaucrat A("A", 1);

        AForm *a = new ShrubberyCreationForm("a");
        AForm *b = new RobotomyRequestForm("b");
        AForm *c = new PresidentialPardonForm("c");

        A.signForm(*a);
        A.executeForm(*a);
        A.executeForm(*b);
        A.executeForm(*c);
    }
}