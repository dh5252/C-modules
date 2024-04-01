
#include "includes/Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& obj)
{
    *this = obj;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &obj)
{
    if (this == &obj)
        return *this;
    return *this;
}

static AForm *makePresidential(std::string target)
{
    return (new PresidentialPardonForm(target));
}

static AForm *makeRobotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *makeShrubbery(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target)
{
    AForm *(*formMakers[])(std::string target) = {&makePresidential, &makeRobotomy, &makeShrubbery};
    std::string formNames[] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};
    for (int i = 0 ; i < 3 ; ++i) {
        if (form == formNames[i]) {
            AForm *newForm = formMakers[i](target);
            std::cout << "Intern creates " << form << std::endl;
            return newForm;
        }
    }
    std::cout << "Intern can't create " << form << std::endl;
    return NULL;
}