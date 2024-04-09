
#include "includes/easyfind.hpp"

#include <vector>
#include <list>

int main() {


    std::cout << "\nVector Test\n";

    std::vector<int> test1;
    for (int i = 0 ; i < 10 ; ++i)
        test1.push_back(i + 1);

    try {
        std::vector<int>::iterator iter1 = easyfind(test1, 3);
        std::cout << "<vector> I find 3" << std::endl;
        iter1 = easyfind(test1, 11);
        std::cout << "<vector> I find 11" << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what();
    }

    std::cout << "\nList Test\n";
    std::list<int> test2;
    for (int i = 0 ; i < 10 ; ++i)
        test2.push_back(i + 1);

    try {
        std::list<int>::iterator iter2 = easyfind(test2, 3);
        std::cout << "<list> I find 3" << std::endl;
        iter2 = easyfind(test2, 11);
        std::cout << "<list> I find 11" << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what();
    }
    return 0;
}