
#include "includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("PresidentialPardonForm", 25, 5)
{
    this->target = _target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &b) const
{
    if (b.getGrade() > this->getGradeForExecute())
        throw Bureaucrat::GradeTooLowException();
    else if (!this->getIsSigned())
        throw NotSignedException();
    else
    {
        std::cout << this->target + " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
}