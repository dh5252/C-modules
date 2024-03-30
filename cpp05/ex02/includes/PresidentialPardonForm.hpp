
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &obj);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
    public:
        ~PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        virtual void execute(Bureaucrat const &b) const;
};


#endif