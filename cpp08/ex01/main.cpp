
#include "includes/Span.hpp"

int main()
{
    {
        std::cout << " \n basic Test \n";
        Span sp = Span(5);

        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        try {
            sp.addNumber(11);
        } catch (std::exception &e) {
            std::cerr << e.what() << "\n";
        }
    }

    {
        std::cout << " \n 10000 Test \n";
        Span sp(20000);

        try {
            sp.addRandomNumberBySize(20000);
        } catch (std::exception &e) {
            std::cerr << e.what() << "\n";
        }
        try {
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << "\n";
        }
    }
}