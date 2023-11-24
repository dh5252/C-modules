

#include "includes/Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "class [Cat] : defalut Constructor called" << std::endl;
}

Cat::Cat(const Cat& obj)
{
    this->type = obj.type;
    std::cout << "class [Cat] : copy Constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "class [Cat] : defalut Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &obj)
{
    this->type = obj.type;
    std::cout << "class [Cat] : = operator is called" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "class [Cat] : ni-yaa-ong" << std::endl;
}