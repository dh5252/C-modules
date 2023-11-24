

#include "includes/WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "class [WrongCat] : defalut Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj)
{
    this->type = obj.type;
    std::cout << "class [WrongCat] : copy Constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "class [WrongCat] : defalut Destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &obj)
{
    this->type = obj.type;
    std::cout << "class [WrongCat] : = operator is called" << std::endl;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "class [WrongCat] : ni-yaa-ong" << std::endl;
}