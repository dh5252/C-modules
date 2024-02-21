
#include "includes/Cure.hpp"

Cure::Cure()
{
    this->type = "cure";
    std::cout << "class [Cure] : defalut Constructor called" << std::endl;
}

Cure::~Cure()
{
    std::cout << "class [Cure] : defalut Destructor called" << std::endl;
}

Cure::Cure(const Cure &obj)
{
    this->type = obj.type;
    std::cout << "class [Cure] : copy Constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &obj)
{
    if (this == &obj)
    {
        std::cout << "class [Cure] : = Operator called" << std::endl;
        return *this;
    }
    this->type = obj.type;
    std::cout << "class [Cure] : = Operator called" << std::endl;
    return *this;
}

AMateria *Cure::clone() const
{
    std::cout << "class [Cure] : clone called" << std::endl;
    return new Cure();
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "`s wounds *" << std::endl;
}
