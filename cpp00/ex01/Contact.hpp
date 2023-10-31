
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phoneNumber;
        std::string secret;
    public:
        Contact();
        Contact(std::string firstname, std::string lastname, std::string nickname, \
            std::string phoneNumber, std::string secret);
        std::string getFirstname();
        std::string getLastname();
        std::string getNickname();
        void        show();
        ~Contact();
};

#endif