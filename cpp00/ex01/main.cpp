
#include "PhoneBook.hpp"

int main()
{
    PhoneBook book;
    std::string cmd;

    std::cout << "Input command : ";
    std::cin >> cmd;
    while (cmd != "EXIT")
    {
        if (cmd == "ADD")
            book.ADD();
        else if (cmd == "SEARCH")
            book.SEARCH();
        std::cout << "Input command : " << std::flush;
        std::cin >> cmd;
    }
}