#include "includes/AMateria.hpp"
#include "includes/Character.hpp"
#include "includes/Cure.hpp"
#include "includes/Ice.hpp"
#include "includes/ICharacter.hpp"
#include "includes/IMateriaSource.hpp"
#include "includes/MateriaSource.hpp"
#include "includes/Floor.hpp"


int main()
{
    {
        std::cout << "\nTest 1 : equip Test\n";
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");

        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter* bob = new Character("bob");

        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }
    
    {
        std::cout << "\nTest 2 : unequipTest\n";
        
        Floor::init();

        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("cahn");

        AMateria* item;
        item = src->createMateria("ice");
        me->equip(item);
        item = src->createMateria("ice");
        me->equip(item);
        item = src->createMateria("ice");
        me->equip(item);

        me->unequip(0);
        me->unequip(1);
        me->unequip(3);
        me->unequip(5);

        delete src;
        delete me;

        Floor::cleanFloor();
    }

    {
        std::cout << "\nTest 3 : CharacterTest\n";
        
        Floor::init();

        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("cahn");

        AMateria* item;
        item = src->createMateria("ice");
        me->equip(item);
        item = src->createMateria("cure");
        me->equip(item);
        
        ICharacter* meCopy = new Character(*(Character *)me);

        meCopy->unequip(0);
        meCopy->unequip(1);

        me->use(0, *meCopy);
        me->use(1, *meCopy);

        delete src;
        delete me;
        delete meCopy;

        Floor::cleanFloor();
    }

    {
        std::cout << "\nTest 4 : FullEquipTest\n";
        
        Floor::init();

        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("cahn");

        AMateria* item;
        item = src->createMateria("ice");
        me->equip(item);
        item = src->createMateria("cure");
        me->equip(item);
        item = src->createMateria("ice");
        me->equip(item);
        item = src->createMateria("cure");
        me->equip(item);
        item = src->createMateria("cure");
        me->equip(item);
        
        delete item;
        delete src;
        delete me;

        Floor::cleanFloor();
    }

    system("leaks ex03");
    return 0;
}