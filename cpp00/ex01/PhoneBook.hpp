
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

    private :
        Contact contacts[8];
        int old;
        int size;
        Contact returnContactByIndex(int index);
        void showContact(int index);
    public :
        PhoneBook();
        PhoneBook(int old, int size);
        ~PhoneBook();
        void SEARCH();
        void ADD();
        int getSize();
        void setSize(int s);
        int getOld();
        void setOld(int o);
};

#endif