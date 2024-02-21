#ifndef FLOORNODE_H
# define FLOORNODE_H

#include "AMateria.hpp"

typedef struct FloorNode
{
    AMateria *materia;
    FloorNode *next;
}   node;


#endif