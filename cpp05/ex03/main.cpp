
#include "includes/Intern.hpp"

int main()
{
    {
        std::cout << "\nIntegrated Test" << std::endl;

        Intern intern;

        AForm *form1 = intern.makeForm("ShrubberyCreation", "target1");
        AForm *form2 = intern.makeForm("RobotomyRequest", "target2");
        AForm *form3 = intern.makeForm("PresidentialPardon", "target3");

        Bureaucrat A("A", 1);

        A.signForm(*form1);
        A.executeForm(*form1);

        A.executeForm(*form2);
        
        A.signForm(*form2);
        A.executeForm(*form2);

        A.signForm(*form3);
        A.decrementGrade(140);
        A.executeForm(*form3);

    }
}