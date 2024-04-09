
#ifndef EASYFIND_HPP
# define EASYFINE_HPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator iter;

    iter = std::find(container.begin(), container.end(), value);
    if (iter == container.end()) {
        throw std::runtime_error("Can't fine value\n");
    }
    return iter;
}


#endif