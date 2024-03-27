
#include "includes/Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
    return "high grade exception";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "low grade exception";
}


Form::Form()
{    
}

Form::Form(const Form &obj) : name(obj.name)
{
    this->isSigned = obj.isSigned;
    this->gradeForExecute = obj.gradeForExecute;
    this->gradeForSigned = obj.gradeForSigned;
}

Form::~Form()
{
}

Form::Form(std::string name, int gradeForSigned, int gradeForExecute) : name(name)
{
    this->gradeForExecute = gradeForExecute;
    this->gradeForSigned = gradeForSigned;
    if (this->gradeForExecute < 1 || this->gradeForSigned < 1)
        throw GradeTooHighException();
    if (this->gradeForExecute > 150 || this->gradeForSigned > 150)
        throw GradeTooLowException();
}

std::string Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeForSigned() const
{
    return gradeForSigned;
}

int Form::getGradeForExecute() const
{
    return gradeForExecute;
}

void Form::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() > this->gradeForSigned)
        throw GradeTooLowException();
    isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << "Form " << obj.getName() << ", is Signed? " << std::boolalpha << obj.getIsSigned() \
     << ", gradeForSigned : " << obj.getGradeForSigned() << " ,gradeForExecute : " << obj.getGradeForExecute() << std::endl;
    return os;
}
