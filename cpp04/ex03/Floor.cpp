
#include "includes/Floor.hpp"

FloorNode* Floor::head = nullptr;
FloorNode* Floor::last = nullptr;

Floor::Floor()
{
    std::cout << "class [Floor] : defalut Constructor called" << std::endl;
}

Floor::~Floor()
{
    std::cout << "class [Floor] : defalut Destructor called" << std::endl;   
}

Floor::Floor(const Floor &obj)
{
    (void)obj;
    std::cout << "class [Floor] : copy Constructor called" << std::endl;   
}

Floor &Floor::operator=(const Floor &obj)
{
    (void)obj;
    std::cout << "class [Floor] : = operator called" << std::endl;
    return *this;
}

void Floor::init()
{
    head = new FloorNode;
    head->materia = NULL;
    head->next = NULL;
    last = head;
    std::cout << "class [Floor] : Floor init" << std::endl;

}

void Floor::cleanFloor()
{
    FloorNode *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        if (tmp->materia)
            delete tmp->materia;
        delete tmp;
    }
    head = NULL;
    last = NULL;
    std::cout << "class [Floor] : Floor is cleaned" << std::endl;

}

void Floor::insertNode(AMateria *m)
{
    FloorNode *newNode = new FloorNode;
    newNode->materia = m;
    newNode->next = NULL;
    last->next = newNode;
    last = newNode;
    std::cout << "class [Floor] : Materia is dropped to floor" << std::endl;
}
