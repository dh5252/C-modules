

#include "includes/Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "class [Dog] : defalut Constructor called" << std::endl;
}

Dog::Dog(const Dog& obj)
{
    this->type = obj.type;
    std::cout << "class [Dog] : copy Constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "class [Dog] : defalut Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &obj)
{
    this->type = obj.type;
    std::cout << "class [Dog] : = operator is called" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "class [Dog] : wall! wall!" << std::endl;
}