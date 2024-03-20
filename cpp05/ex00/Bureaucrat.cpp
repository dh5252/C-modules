
#include "includes/Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade is high...";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade is low...";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    this->grade = grade;
    if (grade < 1) {
        throw GradeTooHighException();
    }
    else if (grade > 150) {
        throw GradeTooLowException();
    }
}