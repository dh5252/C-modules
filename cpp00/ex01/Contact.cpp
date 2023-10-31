#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{   
}

Contact::Contact(std::string firstname, std::string lastname, std::string nickname, \
            std::string phoneNumber, std::string secret)
{
    this->firstname = firstname;
    this->lastname = lastname;
    this->nickname = nickname;
    this->phoneNumber = phoneNumber;
    this->secret = secret;
}

std::string Contact::getFirstname()
{
    return this->firstname;
}

std::string Contact::getLastname()
{
    return this->lastname;
}

std::string Contact::getNickname()
{
    return this->nickname;
}

void    Contact::show()
{
    std::cout << getFirstname() << " " << getLastname() << " " << getNickname() << std::endl;
}