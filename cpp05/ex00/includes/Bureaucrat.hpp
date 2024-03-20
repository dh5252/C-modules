
#ifndef _BUREAUCRAT_HPP
# define _BRUEAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    private :
        const std::string name;
        int grade;
    public :
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat& operator=(const Bureaucrat &obj);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void modifyGrade(int delta);

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

#endif