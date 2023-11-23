
#include "includes/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string n)
{
    name = n;
    AttackDamage = 0;
    HitPoint = 10;
    EnergyPoint = 10;
    std::cout << "ClapTrap : name Constructor called, name is " << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
{
    name = obj.name;
    AttackDamage = obj.AttackDamage;
    HitPoint = obj.HitPoint;
    EnergyPoint = obj.EnergyPoint;
    std::cout << "ClapTrap : Operator = is called, name is " << name << std::endl;
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
    name = obj.name;
    AttackDamage = obj.AttackDamage;
    HitPoint = obj.HitPoint;
    EnergyPoint = obj.EnergyPoint;
    std::cout << "ClapTrap : Copy Constructor is called, name is " << name << std::endl;
}

ClapTrap::ClapTrap()
{
    name = "noName";
    AttackDamage = 0;
    HitPoint = 10;
    EnergyPoint = 10;
    std::cout << "ClapTrap : Defalut Constructor is called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap : Defalut Destructor is called, name is " << name << std::endl; 
}

void ClapTrap::attack(const std::string& target)
{
    if (!HitPoint || !EnergyPoint)
        std::cout << "ClapTrap " << name << " has no hitPoint or energyPoint" << std::endl;
    else
    {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << AttackDamage << " points of damage" << std::endl;
        --EnergyPoint;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (HitPoint == 0)
    {
        std::cout << "ClapTrap " << name << " is attacked, but already dead.." << std::endl;
        return ;
    }
    HitPoint -= amount;
    std::cout << "ClapTrap " << name << " received as much damage as " << amount << std::endl;
    if (HitPoint <= 0)
    {
        HitPoint = 0;
        std::cout << "ClapTrap " << name << " is died" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!HitPoint || !EnergyPoint)
        std::cout << "ClapTrap " << name << " has no hitPoint or energyPoint" << std::endl;
    else
    {
        HitPoint += amount;
        --EnergyPoint;
        std::cout << "ClapTrap " << name << " has been repaired by " << amount << std::endl;
    }
}
