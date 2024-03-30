
#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>


class Bureaucrat;

class AForm
{
    private :
        const std::string name;
        bool isSigned;
        int gradeForSigned;
        int gradeForExecute;
        
        AForm &operator=(const AForm &obj);
        AForm();
    public :
        AForm(std::string name, int gradeForSigned, int gradeForExecute);    
        AForm(const AForm &obj);
        virtual ~AForm();
        
        std::string getName() const;
        int getGradeForSigned() const;
        int getGradeForExecute() const;
        bool getIsSigned() const;
        void beSigned(Bureaucrat &obj);
        virtual void execute(Bureaucrat const &b) const = 0;
        
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

        class NotSignedException : public std::exception
        {
            public :
                const char *what(void) const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif