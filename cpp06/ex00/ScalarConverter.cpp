
#include "includes/ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &input)
{
    double val;

    char *ptr = NULL;
    val = std::strtod(input.c_str(), &ptr);
    try {
        if (val == 0.0 &&
        (input[0] != '+' && input[0] != '-' && !std::isdigit(input[0])) &&
        (*ptr && std::strcmp(ptr, "f")))
        throw std::exception();
    } catch (std::exception &e) {
        std::cout << "Convert fail" << std::endl;
        return;
    }

    std::cout << "char: ";
    if (std::isnan(val) || std::isinf(val)) 
        std::cout << "impossible" << std::endl;
    else if (std::isprint(static_cast<char>(val)))
        std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    std::cout << "int: ";
    if (std::isnan(val) || std::isinf(val) || val > INT_MAX || val < INT_MIN)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(val) << std::endl;

    std::cout << "float: ";
    if (std::isnan(val) || std::isinf(val))
        std::cout << static_cast<float>(val) << "f" << std::endl;
    else if (static_cast<float>(val) == static_cast<int64_t>(static_cast<float>(val)))
        std::cout << static_cast<float>(val) << ".0f" << std::endl;
    else
        std::cout << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<float>(val) << "f" << std::endl;

    std::cout << "double: ";
    if (std::isnan(val) || std::isinf(val))
        std::cout << static_cast<double>(val) << std::endl;
    else if (static_cast<double>(val) == static_cast<int64_t>(static_cast<double>(val)))
        std::cout << static_cast<double>(val) << ".0" << std::endl;
    else
        std::cout << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<double>(val) << std::endl;
}
