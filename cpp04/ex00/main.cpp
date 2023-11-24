
#include "includes/Animal.hpp"
#include "includes/Cat.hpp"
#include "includes/Dog.hpp"
#include "includes/WrongCat.hpp"

int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete i;
        delete j;
    }
    std::cout << "\n----------------  wrong_test  ------------------------\n" << std::endl;
    {
        const WrongAnimal *test1 = new WrongAnimal();
        const WrongAnimal *test2 = new WrongCat();

        std::cout << test1->getType() << " " << std::endl;
        std::cout << test2->getType() << " " << std::endl;
        test1->makeSound();
        test2->makeSound();
        
        delete test1;
        delete test2;
    }
    return 0;
}