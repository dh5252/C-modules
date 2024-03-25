
#ifndef _BUREAUCRAT_HPP
# define _BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    private :
        const std::string name;
        int grade;
    public :
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void incrementGrade(unsigned int abs);
        void decrementGrade(unsigned int abs);

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

std::ostream& operator<<(std::ostream& os,  const Bureaucrat& obj);


#endif