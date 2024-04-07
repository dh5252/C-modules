
#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *addr, size_t len, void (*fn)(T&))
{
    for (size_t i = 0 ; i < len ; ++i)
        fn(addr[i]);
}

template<typename T>
void print(T &t)
{
    std::cout << t;
}


#endif