
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &obj);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
    public:
        ~RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        virtual void execute(Bureaucrat const &b) const;
};


#endif