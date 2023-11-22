

#include "includes/ClapTrap.hpp"

int main()
{
    ClapTrap A("cahn");
    ClapTrap B("Blackhole");

    B.attack("cahn");
    A.takeDamage(0);
    A.beRepaired(10);
    A.attack("Blackhole");
    B.takeDamage(100);
    B.beRepaired(50);
}