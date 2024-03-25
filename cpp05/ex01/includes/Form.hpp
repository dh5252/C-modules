
#ifndef _FORM_HPP
# define _FORM_HPP

#include <iostream>

class Form
{
    private :
        const std::string name;
        bool isSigned;
        int gradeForSigned;
        int gradeForExecute;

    public :
        Form(std::string name, bool isSigned, int gradeForSigned, int gradeForExecute);
        Form(const Form &obj);
        ~Form();

        std::string getName() const;
        int getGradeForSigned() const;
        int getGradeForExecute() const;
        
        // class GradeTooHighException : public std::exception
        // {
        //     public :
        //         const char *what(void)
        // }
};



#endif