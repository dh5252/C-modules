
#include "includes/RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Argument is not valid.\n";
        return (0); 
    }

    RPN a(argv[1]);

    try {
        int res = a.execute();
        std::cout << res << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}