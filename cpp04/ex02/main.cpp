
#include "includes/Animal.hpp"
#include "includes/Cat.hpp"
#include "includes/Dog.hpp"
#include "includes/WrongCat.hpp"

int main()
{
    const Animal *array[6] = {new Dog(), new Dog(), new Dog(), new Cat(), new Cat(), new Cat()};
    //const Animal *array2[6] = {new Animal(), new Dog(), new Dog(), new Cat(), new Cat(), new Cat()};

    std::cout << "\nType Test : \n" << std::endl;
    {
        for (int i = 0 ; i < 6 ; ++i)
            std::cout << "array [" << i << "] types : " << array[i]->getType() << std::endl;
    }

    std::cout << "\nCopy Test : \n" << std::endl;
    {
        Dog *test = (Dog *)array[0];
        test->makeSound();

        Dog test2(*(Dog *)array[0]);
        test2.makeSound();

        Dog test3;
        test3 = (*(Dog *)array[0]);
        test3.makeSound();
    }

    std::cout << "\nBrain Test : \n" << std::endl;
    {
        Dog *test = (Dog *)array[0];
        test->getBrain()->setIdeaByIndex("hungry....", 0);

        Dog test2(*(Dog *)array[0]);
        std::cout << "copy check : " << test2.getBrain()->getIdeaByIndex(0) << std::endl;

        test2.getBrain()->setIdeaByIndex("I want to walk...", 1);
        std::cout << "deep copy check : " << test->getBrain()->getIdeaByIndex(1) << std::endl;
    }

    std::cout << "\nAbstract Test : \n" << std::endl;
    {
        //Animal test(*(Animal *)array[0]);
    }
    
    std::cout << "\nFree Test : \n" << std::endl;
    {
        for (int i = 0 ; i < 6 ; ++i)
            delete array[i];
    }

    return 0;
}