
#include "includes/A.hpp"
#include "includes/B.hpp"
#include "includes/C.hpp"
#include <cstdlib>
#include <ctime>

Base::~Base(){
}

Base* generate(void) 
{
    srand(static_cast<unsigned int>(time(0)));
    int random = rand() % 3;

    if (random == 0) {
        std::cout << "Create A" << std::endl;
        return new A();
    }
    else if (random == 1) {
        std::cout << "Create B" << std::endl;
        return new B();
    }
    else {
        std::cout << "Create C" << std::endl;
        return new C();
    }
    return NULL;
}

void identify(Base *p) {

    if (dynamic_cast<A*>(p))
        std::cout << "Pointer A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Pointer B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Pointer C" << std::endl;
}

void identify(Base &p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Reference A" << std::endl;
    } catch (std::exception &e){
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "Reference B" << std::endl;
        } catch (std::exception &e){
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "Reference C" << std::endl;
            } catch (std::exception &e){
            }
        }
    }
}