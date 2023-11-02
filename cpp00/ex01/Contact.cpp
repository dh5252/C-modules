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

std::string Contact::getPhoneNumber()
{
    return this->phoneNumber;
}

std::string Contact::getSecret()
{
    return this->secret;
}
