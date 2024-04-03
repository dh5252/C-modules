
#include "includes/ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "need only one argument\n";
        return 0;
    }

    ScalarConverter::convert(argv[1]);

    return 0;
}