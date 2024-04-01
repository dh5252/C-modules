
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private :
        const std::string name;
        int grade;

        Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &obj);
    public :
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void incrementGrade(unsigned int abs);
        void decrementGrade(unsigned int abs);
        void signForm(AForm &form);
        void executeForm(AForm const &form);

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);


#endif