
#include "includes/Bureaucrat.hpp"

int main()
{
    {
        std::cout << "\n<Integrity Test>" << std::endl;
        Form A("formA", 10, 5);
        Bureaucrat B("BureaucratB", 10);

        B.signForm(A);

        B.decrementGrade(1);

        Form C("formC", 10, 5);
        B.signForm(C);

        std::cout << "\n<cout Test>" << std::endl;

        std::cout << C;
    }
    
}