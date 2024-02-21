

#include "includes/Brain.hpp"

Brain::Brain()
{
    std::cout << "class [Brain] : Default Constructor is called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "class [Brain] : Default Destructor is called" << std::endl;
}

Brain::Brain(const Brain& obj)
{
    for (int i = 0 ; i < 100 ; ++i)
        this->ideas[i] = obj.ideas[i];
    std::cout << "class [Brain] : Copy Constructor is called" << std::endl;
}

Brain& Brain::operator=(const Brain& obj)
{
    if (this == &obj) 
    {
        std::cout << "class [Brain] : = operator is called" << std::endl;
        return *this;
    }
    for (int i = 0 ; i < 100 ; ++i)
        this->ideas[i] = obj.ideas[i];
    std::cout << "class [Brain] : = operator is called" << std::endl;
    return *this;
}

std::string Brain::getIdeaByIndex(unsigned int index) const
{
    index %= 100;
    return ideas[index];
}

void Brain::setIdeaByIndex(std::string idea, unsigned int index)
{
    index %= 100;
    ideas[index] = idea;
}
