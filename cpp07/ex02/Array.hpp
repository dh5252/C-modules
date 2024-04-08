
#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>

template <typename T>
class Array
{
    private:
        unsigned int len;
        T *array;
    public:

        Array() {
            len = 0;
            array = NULL;
        }

        Array(unsigned int n) {
            len = n;
            array = new T[n];
        }

        Array(const Array &obj) {
            if (obj.len == 0) {
                array = NULL;
                len = 0;
                return ;
            }
            array = new T[obj.len];
            len = obj.len;
            for (size_t i = 0 ; i < len ; ++i)
                array[i] = obj.array[i];
        }

        Array &operator=(const Array &obj) {
            if (this == &obj)
                return *this;
            if (obj.len == 0) {
                array = NULL;
                len = 0;
                return *this;
            }
            array = new T[obj.len];
            len = obj.len;
            for (size_t i = 0; i < len ; ++i)
                array[i] = obj.array[i];
            return *this;
        }

        ~Array() {
            if (array != NULL)
                delete array;
        }

        size_t size() const {
            return len;
        }

        T& operator[] (long long i) {
            if (i < 0 || i >= len)
                throw OutOfBounds();
            return array[i];
        }
        const T& operator[] (long long i) const {
            if (i < 0 || i >= len)
                throw OutOfBounds();
            return array[i];
        }

        class OutOfBounds : public std::exception {
            public:
                const char *what() const throw() {
                    return "OutOfRange";
                }
        };
};

#endif