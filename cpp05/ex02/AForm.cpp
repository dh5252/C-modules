
#include "includes/AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
    return "high grade exception";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "low grade exception";
}

const char *AForm::NotSignedException::what() const throw()
{
    return "Not signed Exception";
}

AForm::AForm(const AForm &obj) : name(obj.name)
{
    this->isSigned = obj.isSigned;
    this->gradeForExecute = obj.gradeForExecute;
    this->gradeForSigned = obj.gradeForSigned;
}

AForm::~AForm()
{
}

AForm::AForm(std::string name, int gradeForSigned, int gradeForExecute) : name(name)
{
    this->gradeForExecute = gradeForExecute;
    this->gradeForSigned = gradeForSigned;
    if (this->gradeForExecute < 1 || this->gradeForSigned < 1)
        throw GradeTooHighException();
    if (this->gradeForExecute > 150 || this->gradeForSigned > 150)
        throw GradeTooLowException();
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeForSigned() const
{
    return gradeForSigned;
}

int AForm::getGradeForExecute() const
{
    return gradeForExecute;
}

void AForm::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() > this->gradeForSigned)
        throw GradeTooLowException();
    isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    os << "Form " << obj.getName() << ", is Signed? " << std::boolalpha << obj.getIsSigned() \
     << ", gradeForSigned : " << obj.getGradeForSigned() << " ,gradeForExecute : " << obj.getGradeForExecute() << std::endl;
    return os;
}
