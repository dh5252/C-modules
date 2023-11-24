

#include "includes/Animal.hpp"

Animal::Animal()
{    
    this->type = "noType";
    std::cout << "class [Animal] : defalut Constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "class [Animal] : defalut Destructor called" << std::endl;
}

Animal::Animal(const Animal& obj)
{    
    this->type = obj.type;
    std::cout << "class [Animal] : copy Constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &obj)
{
    this->type = obj.type;
    std::cout << "class [Animal] : = operator called" << std::endl;
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "class [Animal] : no Sound" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}