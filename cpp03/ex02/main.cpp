

#include "includes/FragTrap.hpp"

int main()
{
    FragTrap A("cahn");
    FragTrap B("Blackhole");

    B.attack("cahn");
    A.takeDamage(20);
    A.beRepaired(10);
    A.highFivesGuys();
    A.attack("Blackhole");
    B.takeDamage(20);
    B.beRepaired(50);
    B.highFivesGuys();
}