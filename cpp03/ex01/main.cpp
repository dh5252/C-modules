

#include "includes/ScavTrap.hpp"

int main()
{
    ScavTrap A("cahn");
    ScavTrap B("Blackhole");

    B.attack("cahn");
    A.takeDamage(20);
    A.beRepaired(10);
    A.guardGate();
    A.attack("Blackhole");
    B.takeDamage(20);
    B.beRepaired(50);
    B.guardGate();
}