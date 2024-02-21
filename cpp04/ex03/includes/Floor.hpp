
#ifndef FLOOR_HPP
# define FLOOR_HPP

#include "FloorNode.h"

class Floor
{
    private:
        static FloorNode* head;
        static FloorNode* last;
    public:
        Floor();
        ~Floor();
        Floor(const Floor &obj);
        Floor &operator=(const Floor &obj);

        static void insertNode(AMateria *m);
        static void cleanFloor();
        static void init();
};

#endif