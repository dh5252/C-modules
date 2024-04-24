
#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <list>
#include <sstream>

class RPN
{
    private:
        std::stack<int> stk;
        std::list<std::string> elements;
        std::string expression;
        void makeElementsList();
        void isValidElementsList();
        int calculate();

    public:
        RPN();
        ~RPN();
        RPN(std::string expression);
        RPN(const RPN &obj);
        RPN &operator=(const RPN &obj);
        int execute();
};

#endif