
#include "includes/AMateria.hpp"

AMateria::AMateria()
{
    this->type = "noType";
    std::cout << "class [AMateria] : defalut Constructor called" << std::endl;
}

AMateria::AMateria(std::string const &_type) : type(_type) 
{
    std::cout << "class [AMateria] : type Constructor called" << std::endl;
}

AMateria::~AMateria() 
{
    std::cout << "class [AMateria] : defalut Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &obj)
{
    *this = obj;
    std::cout << "class [AMateria] : copy Constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &obj)
{
    if (this == &obj)
    {
        std::cout << "class [AMateria] : = Operator called" << std::endl;
        return *this;
    }
    this->type = obj.type;
    return *this;
}

void AMateria::use(ICharacter &target) 
{
    std::cout << "AMateria use on " << target.getName() << std::endl;
}

std::string const &AMateria::getType() const 
{
    return this->type;
}