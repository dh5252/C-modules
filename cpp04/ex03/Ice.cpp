
#include "includes/Ice.hpp"

Ice::Ice()
{
    this->type = "ice";
    std::cout << "class [Ice] : defalut Constructor called" << std::endl;
}

Ice::~Ice()
{
    std::cout << "class [Ice] : defalut Destructor called" << std::endl;
}

Ice::Ice(const Ice &obj)
{
    this->type = obj.type;
    std::cout << "class [Ice] : copy Constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &obj)
{
    if (this == &obj)
    {
        std::cout << "class [Ice] : = Operator called" << std::endl;
        return *this;
    }
    this->type = obj.type;
    std::cout << "class [Ice] : = Operator called" << std::endl;
    return *this;
}

AMateria *Ice::clone() const
{
    std::cout << "class [Ice] : clone called" << std::endl;
    return new Ice();
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
