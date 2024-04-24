
#include "includes/RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(std::string _expression)
{
    this->expression = _expression;
}
        
RPN::RPN(const RPN &obj)
{
    this->expression = obj.expression;
    this->stk = obj.stk;
    this->elements = obj.elements;
}

RPN &RPN::operator=(const RPN &obj)
{
    if (this == &obj)
        return *this;
    this->expression = obj.expression;
    this->stk = obj.stk;
    this->elements = obj.elements;
    return *this;
}

void RPN::makeElementsList()
{
    std::stringstream ss(expression);
    std::string buf;

    while (getline(ss, buf, ' '))
        this->elements.push_back(buf);
    
    this->isValidElementsList();
}

void RPN::isValidElementsList()
{
    std::list<std::string>::iterator it = elements.begin();
    
    while (it != elements.end()) {
        if (it->length() != 1)
            throw std::runtime_error("Error");
        if (!std::isdigit((*it)[0]) && *it != "+" && *it != "-" && *it != "*" && *it != "/")
            throw std::runtime_error("Error");
        it++;
    }
}

int RPN::calculate()
{
    std::list<std::string>::iterator it = elements.begin();
    while (it != elements.end()) {
        
        if (std::isdigit((*it)[0]))
            stk.push((*it)[0] - '0');
        else {
            if (stk.size() <= 1)
                throw std::runtime_error("Error");
            int n1 = stk.top();
            stk.pop();
            int n2 = stk.top();
            stk.pop();
            if (*it == "+")
                stk.push(n2 + n1);
            else if (*it == "-")
                stk.push(n2 - n1);
            else if (*it == "*")
                stk.push(n2 * n1);
            else if (*it == "/") {
                if (n1 == 0)
                    throw std::runtime_error("division 0 Error");
                stk.push(n2 / n1);
            }
        }
        ++it;
    }
    if (stk.size() != 1)
        throw std::runtime_error("Error");
    return stk.top();
}

int RPN::execute()
{
    this->makeElementsList();
    return (this->calculate());
}
