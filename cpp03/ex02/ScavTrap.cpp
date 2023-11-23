
#include "includes/ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    name = "noName";
    HitPoint = 100;
    EnergyPoint = 50;
    AttackDamage = 20;

    std::cout << "ScavTrap : default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string n)
{
    name = n;
    HitPoint = 100;
    EnergyPoint = 50;
    AttackDamage = 20;

    std::cout << "ScavTrap : name Constructor called, name is " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
    name = obj.name;
    HitPoint = obj.HitPoint;
    EnergyPoint = obj.EnergyPoint;
    AttackDamage = obj.AttackDamage;

    std::cout << "ScavTrap : Copy Constructor is called, name is " << name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    name = obj.name;
    HitPoint = obj.HitPoint;
    EnergyPoint = obj.EnergyPoint;
    AttackDamage = obj.AttackDamage;
    std::cout << "ScavTrap : Operator = is called, name is " << name << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap : Defalut Destructor is called, name is " << name << std::endl; 
}

void ScavTrap::attack(std::string const& target)
{
    if (!HitPoint || !EnergyPoint)
        std::cout << "ScavTrap " << name << " has no hitPoint or energyPoint" << std::endl;
    else
    {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << AttackDamage << " points of damage" << std::endl;
        --EnergyPoint;
    }
}

void ScavTrap::guardGate()
{
    if (!HitPoint)
    {
        std::cout << "ScavTrap " << name << " is already dead..." << std::endl;
        return ;
    }
    std::cout << "[ScavTrap Gate Keeper Mode]" << std::endl;
}



