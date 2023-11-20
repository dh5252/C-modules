
#include "includes/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string n)
{
    name = n;
    AttackDamage = 0;
    HitPoint = 10;
    EnergyPoint = 10;
    std::cout << "name Constructor called, name is " << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
{
    name = obj.name;
    AttackDamage = obj.AttackDamage;
    HitPoint = obj.HitPoint;
    EnergyPoint = obj.EnergyPoint;
    std::cout << "Operator = is called, name is " << name << std::endl;
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
    name = obj.name;
    AttackDamage = obj.AttackDamage;
    HitPoint = obj.HitPoint;
    EnergyPoint = obj.EnergyPoint;
    std::cout << "Copy Constructor is called, name is " << name << std::endl;
}

ClapTrap::ClapTrap()
{
    name = "noName";
    AttackDamage = 0;
    HitPoint = 10;
    EnergyPoint = 10;
    std::cout << "Defalut Constructor is called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Defalut Destructor is called, name is " << name << std::endl; 
}

void ClapTrap::attack(const std::string& target)
{
    if (!HitPoint || !EnergyPoint)
        std::cout << "No Energy Point or No Hit Point, name is " << name << std::endl;
    else
    {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << AttackDamage << " points of damage" << std::endl;
        --EnergyPoint;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    
}

void ClapTrap::beRepaired(unsigned int amount)
{
    
}