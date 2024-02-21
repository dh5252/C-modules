
#include "includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0 ; i < 4 ; ++i)
        this->materia[i] = NULL;
    std::cout << "class [MateriaSource] : defalut Constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0 ; i < 4 ; ++i)
        if (this->materia[i])
            delete this->materia[i];
    std::cout << "class [MateriaSource] : defalut Destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
    *this = obj;
    std::cout << "class [MateriaSource] : copy Constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &obj)
{
    if (this == &obj)
    {
        std::cout << "class [MateriaSource] : = Operator called" << std::endl;
        return *this;
    }
    for (int i = 0 ; i < 4; ++i)
    {
        if (this->materia[i])
            delete this->materia[i];
        this->materia[i] = NULL;
        if (obj.materia[i])
            this->materia[i] = obj.materia[i]->clone();
    }
    std::cout << "class [MateriaSource] : = Operator called" << std::endl;
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0 ; i < 4 ; ++i)
    {
        if (this->materia[i] == NULL)
        {
            this->materia[i] = m;
            std::cout << "class [MateriaSource] : learned" << m->getType() << std::endl;
            return ;
        }
    }
    std::cout << "class [MateriaSource] : max learned materia is 4" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    std::cout << "class [MateriaSource] : createMateria called" << std::endl;
    for (int i = 0 ; i < 4; ++i)
    {
        if (this->materia[i] && this->materia[i]->getType() == type)
        {
            std::cout << "class [MateriaSource] : createMateria : " << type << " is copied" << std::endl;
            return this->materia[i]->clone();
        }
    }

    std::cout << "class [MateriaSource] : createMateria : not find Type" << std::endl;
    return 0;
}
