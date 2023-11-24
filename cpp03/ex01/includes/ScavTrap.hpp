

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
    public:
        ScavTrap();
        ScavTrap(std::string n);
        ScavTrap(const ScavTrap &obj);
        ScavTrap& operator=(const ScavTrap &obj);
        ~ScavTrap();
        void guardGate(void);
        void attack(std::string const& target);
};

#endif