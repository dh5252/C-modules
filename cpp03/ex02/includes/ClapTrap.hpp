
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    protected : 
        std::string     name;
        int             HitPoint;
        unsigned int    EnergyPoint;
        unsigned int    AttackDamage;

    public :
        ClapTrap();
        ClapTrap(std::string n);
        ClapTrap(const ClapTrap& src);
        virtual ~ClapTrap();
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ClapTrap& operator=(const ClapTrap& obj);
};

#endif