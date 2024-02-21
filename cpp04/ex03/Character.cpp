
#include "includes/Character.hpp"
#include "includes/Floor.hpp"

Character::Character()
{
    this->name = "noName";
    for (int i = 0 ; i < 4 ; ++i)
        this->materia[i] = NULL;
    std::cout << "class [Character] : defalut Constructor called" << std::endl;
}

Character::Character(std::string const &_name) : name(_name)
{
    for (int i = 0 ; i < 4 ; ++i)
        this->materia[i] = NULL;
    std::cout << "class [Character] : name Constructor called" << std::endl;
}

Character::~Character()
{
    for (int i = 0 ; i < 4 ; ++i)
        if (this->materia[i] != NULL)
            delete this->materia[i];
    std::cout << "class [Character] : defalut Destructor called" << std::endl;
}

Character::Character(const Character &obj)
{
    *this = obj;
    std::cout << "class [Character] : copy Constructor called" << std::endl;
}

Character &Character::operator=(const Character &obj)
{
    if (this == &obj)
    {
        std::cout << "class [Character] : = Operator called" << std::endl;
        return *this;
    }
    this->name = obj.name;
    for (int i = 0 ; i < 4 ; ++i)
    {
        if (this->materia[i] != NULL)
            delete this->materia[i];
        this->materia[i] = NULL;
        if (obj.materia[i])
            this->materia[i] = obj.materia[i]->clone();
    }
    std::cout << "class [Character] : = Operator called" << std::endl;
    return *this;
}

std::string const &Character::getName() const {
    return this->name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0 ; i < 4 ; ++i)
    {
        if (this->materia[i] == NULL)
        {
            this->materia[i] = m;
            std::cout << "class [Character] : equip called" << std::endl;
            return;
        }
    }
    std::cout << "class [Character] : equip called but already full" << std::endl;

}

void Character::unequip(int idx)
{
    if (!(idx >= 0 && idx < 4))
    {
        std::cout << "class [Character] : unequip called but idx is error" << std::endl;
        return ;
    }
    if (this->materia[idx])
    {
        Floor::insertNode(this->materia[idx]);
        this->materia[idx] = NULL;
        std::cout << "class [Character] : unequip called" << std::endl;
    }
    else
        std::cout << "class [Character] : unequip called but no materia" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
    if (!(idx >= 0 && idx < 4))
    {
        std::cout << "class [Character] : use called but idx is error" << std::endl;
        return ;
    }
    this->materia[idx]->use(target);
    std::cout << "class [Character] : use called" << std::endl;
}