
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iomanip>
#include <limits>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);
        ScalarConverter &operator=(const ScalarConverter &obj);

    public:
        ~ScalarConverter();
        static void convert(const std::string &input);
};

#endif