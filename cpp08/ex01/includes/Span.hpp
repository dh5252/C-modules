
#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <set>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>

class Span
{
    private:
        unsigned int N;
        std::multiset<int> nums;
        Span();
    public:
        Span(unsigned int n);
        Span &operator=(const Span &obj);
        ~Span();
        void addNumber(int num);
        unsigned long long longestSpan() const;
        unsigned long long shortestSpan() const;
        void addRandomNumberBySize(int _size);


        class FullException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class SpanCountException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif