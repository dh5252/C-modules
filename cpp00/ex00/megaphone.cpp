#include <iostream>

std::string convertToUpper(std::string str)
{
    for (size_t i = 0 ; i < str.length() ; i++)
        str[i] = toupper(str[i]);
    return str;
}


int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }
    for (int i = 1 ; i < argc ; i++)
        std::cout << convertToUpper(argv[i]);
    std::cout << "\n";
    return 0;
}