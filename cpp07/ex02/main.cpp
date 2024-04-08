#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "\ncopy Test\n";
        int flag = 0;
        for (int i = 0 ; i < MAX_VAL ; ++i) {
            if (!(numbers[i] == tmp[i] && tmp[i] == test[i])) {
                std::cout << "error!\n";
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            std::cout << "success!\n";
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {              
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nAssignment Test\n";
    int flag = 0;
    for (int i = 0; i < MAX_VAL; i++)
    {
        int tmp = rand();
        numbers[i] = tmp;
        if (numbers[i] != tmp) {
            flag = 1;
            std::cout << "error!\n";
            break;
        }
    }
    if (flag == 0)
        std::cout << "success!\n";
    

    delete [] mirror;
    return 0;
}