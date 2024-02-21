

#include "includes/Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "class [Dog] : defalut Constructor called" << std::endl;
}

Dog::Dog(const Dog& obj)
{
    this->type = obj.type;
    this->brain = new Brain();
    if (obj.brain != NULL)
    {
        for (int i = 0 ; i < 100 ; ++i)
            (this->brain)->setIdeaByIndex(obj.brain->getIdeaByIndex(i), i);
    }
    else
        std::cout << "class [Dog] : Brain of obj is not initialized" << std::endl;
    std::cout << "class [Dog] : copy Constructor called" << std::endl;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "class [Dog] : defalut Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &obj)
{
    if (this == &obj)
    {
        std::cout << "class [Dog] : = operator is called" << std::endl;
        return *this;
    }
    this->type = obj.type;
    if (obj.brain != NULL)
    {
        for (int i = 0 ; i < 100 ; ++i)
            (this->brain)->setIdeaByIndex(obj.brain->getIdeaByIndex(i), i);
    }
     else
        std::cout << "class [Dog] : Brain of obj is not initialized" << std::endl;
    std::cout << "class [Dog] : = operator is called" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "class [Dog] : wall! wall!" << std::endl;
}

Brain* Dog::getBrain() const
{
    return brain;
}