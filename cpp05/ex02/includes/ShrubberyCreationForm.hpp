
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &obj);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
    public:
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        virtual void execute(Bureaucrat const &b) const;
};


#endif