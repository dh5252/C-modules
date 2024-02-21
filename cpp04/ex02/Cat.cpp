

#include "includes/Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "class [Cat] : defalut Constructor called" << std::endl;
}

Cat::Cat(const Cat& obj)
{
    this->type = obj.type;
    this->brain = new Brain();
    if (obj.brain != NULL)
    {
        for (int i = 0 ; i < 100 ; ++i)
            (this->brain)->setIdeaByIndex(obj.brain->getIdeaByIndex(i), i);
    }
    else
        std::cout << "class [Cat] : Brain of obj is not initialized" << std::endl;
    std::cout << "class [Cat] : copy Constructor called" << std::endl;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "class [Cat] : defalut Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &obj)
{
    if (this == &obj)
    {
        std::cout << "class [Cat] : = operator is called" << std::endl;
        return *this;
    }
    this->type = obj.type;
    if (obj.brain != NULL)
    {
        for (int i = 0 ; i < 100 ; ++i)
            (this->brain)->setIdeaByIndex(obj.brain->getIdeaByIndex(i), i);
    }
     else
        std::cout << "class [Cat] : Brain of obj is not initialized" << std::endl;
    std::cout << "class [Cat] : = operator is called" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "class [Cat] : ni-yaa-ong" << std::endl;
}

Brain* Cat::getBrain() const
{
    return brain;
}
