#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->old = 0;
    this->size = 0;
}

PhoneBook::~PhoneBook()
{
}

Contact PhoneBook::returnContactByIndex(int index)
{
    return this->contacts[index];
}

void PhoneBook::showContact(int index)
{
    Contact cont = returnContactByIndex(index);
    std::string fn = cont.getFirstname();
    std::string ln = cont.getLastname();
    std::string nn = cont.getNickname();
    
    std::cout << index << "|";
    for (size_t i = 0 ; i < 10 && i < fn.length() ; i++)
    {
        if (i == 9)
            std::cout << ".";
        else
            std::cout << fn[i];
    }
    std::cout << "|";
    for (size_t i = 0 ; i < 10 && i < ln.length() ; i++)
    {
        if (i == 9)
            std::cout << ".";
        else
            std::cout << ln[i];
    }
    std::cout << "|";
    for (size_t i = 0 ; i < 10 && i < nn.length() ; i++)
    {
        if (i == 9)
            std::cout << ".";
        else
            std::cout << nn[i];
    }
    std::cout << "\n";
}

void PhoneBook::SEARCH()
{
    int index;

    std::cout << "All Contacts : \n\n";
    for (int i = 0 ; i < size ; i++)
        showContact(i);
    std::cout << "\ninput index : ";
    std::cin >> index;
    if (std::cin.fail())
    {
        std::cout << "\nInput number! : " << std::flush;
        std::cin.clear();
        std::cin.ignore(9223372036854775807, '\n');
        std::cout << "\nindex error\n";
        return;
    }
    if (index >= 0 && index < size)
    {
        std::cout << "\nContact you want : ";
        showContact(index);
        std::cout << "\n";
    }
    return ;
}

void PhoneBook::ADD()
{
    std::string fn;
    std::string ln;
    std::string nn;
    std::string pn;
    std::string s;

    std::cout << "Input your FirstName : ";
    std::cin >> fn;

    std::cout << "Input your LastName : ";
    std::cin >> ln;

    std::cout << "Input your NickName : ";
    std::cin >> nn;

    std::cout << "Input your PhoneNumber : ";
    std::cin >> pn;

    std::cout << "Input your Secret : ";
    std::cin >> s;

    std::cout << "Done.\n";

    Contact tmp(fn, ln, nn, pn, s);
    if (size < 8)
        contacts[size++] = tmp;
    else
    {
        contacts[old] = tmp;
        old = (old + 1) % 8;
    }
}