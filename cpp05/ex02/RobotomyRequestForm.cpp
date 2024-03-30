
#include "includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("RobotomyRequestForm", 72, 45)
{
    this->target = _target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &b) const
{
    if (b.getGrade() > this->getGradeForExecute())
        throw Bureaucrat::GradeTooLowException();
    else if (!this->getIsSigned())
        throw NotSignedException();
    else
    {
        std::cout << "drill : Zzzzzzzzzzzzzzzz" << std::endl;

        if (rand() % 2)
            std::cout << this->getName() + " : robotomized success!" << std::endl;
        else
            std::cout << this->getName() + " : robotomized fail!" << std::endl;
    }
}