
#include "includes/Iter.hpp"

int main()
{
    int array1[5] = {1,2,3,4,5};
    char array2[8] = {'\n','4','2','s','e','o','u','l'};

    std::string array3[3] = {"\nHi, ", "I'm cahn. ", "what your name?\n"};

    
    ::iter(array1, 5,::print);
    ::iter(array2, 8,::print);
    ::iter(array3, 3,::print);

}