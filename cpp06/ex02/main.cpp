
#include "includes/Base.hpp"

int main()
{
    {
        std::cout << "Integrated Test" << std::endl;

        Base *test = generate();

        identify(test);
        identify(*test);
    }
}