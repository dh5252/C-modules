
#include "includes/FragTrap.hpp"

FragTrap::FragTrap()
{
    name = "noName";
    HitPoint = 100;
    EnergyPoint = 50;
    AttackDamage = 20;

    std::cout << "FragTrap : default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string n)
{
    name = n;
    HitPoint = 100;
    EnergyPoint = 100;
    AttackDamage = 30;

    std::cout << "FragTrap : name Constructor called, name is " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj)
{
    name = obj.name;
    HitPoint = obj.HitPoint;
    EnergyPoint = obj.EnergyPoint;
    AttackDamage = obj.AttackDamage;

    std::cout << "FragTrap : Copy Constructor is called, name is " << name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
    name = obj.name;
    HitPoint = obj.HitPoint;
    EnergyPoint = obj.EnergyPoint;
    AttackDamage = obj.AttackDamage;
    std::cout << "FragTrap : Operator = is called, name is " << name << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap : Defalut Destructor is called, name is " << name << std::endl; 
}

void FragTrap::highFivesGuys()
{
    if (!HitPoint)
        std::cout << "FragTrap : " << name << " is already dead" << std::endl;
    else
        std::cout << "FragTrap : " << name << " [High Five!]" << std::endl; 
}


