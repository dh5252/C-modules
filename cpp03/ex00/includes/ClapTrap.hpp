
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    private : 
        std::string name;
        unsigned int HitPoint;
        unsigned int EnergyPoint;
        unsigned int AttackDamage;

    public :
        ClapTrap();
        ~ClapTrap();
        ClapTrap(std::string n);
        ClapTrap(const ClapTrap& src);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        unsigned int getHitPoint();
        unsigned int getEnergyPoint();
        unsigned int getAttackDamage();
        std::string getName();
        ClapTrap& operator=(const ClapTrap& obj);
};

#endif