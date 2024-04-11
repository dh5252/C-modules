
#include "includes/Span.hpp"

const char *Span::FullException::what() const throw()
{
    return "Span is full";
}

const char *Span::SpanCountException::what() const throw()
{
    return "size is under 2";
}

Span::Span(unsigned int n) 
{
    this->N = n;
}

Span &Span::operator=(const Span &obj)
{
    if (this == &obj)
        return *this;
    
    this->nums = obj.nums;
    this->N = obj.N;
    return *this;
}

void Span::addNumber(int num)
{
    if (nums.size() == this->N)
        throw FullException();
    nums.insert(num);
}

void Span::addRandomNumberBySize(int _size)
{
    if (nums.size() + _size > N)
        throw FullException();
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0 ; i < _size ; ++i)
        nums.insert(rand());
}

Span::~Span() {};

unsigned long long Span::shortestSpan() const
{
    if (nums.size() <= 1)
        throw SpanCountException();
    unsigned long long value = INT_MAX;

    std::multiset<int>::iterator it = this->nums.begin();
    std::multiset<int>::iterator before = this->nums.begin();
    it++;
    for ( ; it != this->nums.end() ; ++it, ++before)
        value = std::min(value, (unsigned long long)*it - *before);
    return value;
}

unsigned long long Span::longestSpan() const
{
    if (nums.size() <= 1)
        throw SpanCountException();

    std::multiset<int>::iterator rear = this->nums.end();
    rear--;
    return *rear - *this->nums.begin();
}

