
#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private :
        const std::string name;
        bool isSigned;
        int gradeForSigned;
        int gradeForExecute;

    public :
        Form(std::string name, int gradeForSigned, int gradeForExecute);
        Form(const Form &obj);
        ~Form();
        Form();

        std::string getName() const;
        int getGradeForSigned() const;
        int getGradeForExecute() const;
        bool getIsSigned() const;
        void beSigned(Bureaucrat &obj);
        
        class GradeTooHighException : public std::exception
        {
            public :
                const char *what(void) const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public :
                const char *what(void) const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif