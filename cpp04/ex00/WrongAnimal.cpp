
#include "includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{    
    this->type = "noType";
    std::cout << "class [WrongAnimal] : defalut Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "class [WrongAnimal] : defalut Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{    
    this->type = obj.type;
    std::cout << "class [WrongAnimal] : copy Constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj)
{
    if (this == &obj)
    {
        std::cout << "class [WrongAnimal] : = operator called" << std::endl;
        return *this;
    }
    this->type = obj.type;
    std::cout << "class [WrongAnimal] : = operator called" << std::endl;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "class [WrongAnimal] : no Sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}