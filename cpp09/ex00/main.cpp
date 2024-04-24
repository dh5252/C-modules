
#include "includes/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Argument is not valid.\n";
        return (0); 
    }
    BitcoinExchange a(argv[1]);

    try {
        a.execute();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}