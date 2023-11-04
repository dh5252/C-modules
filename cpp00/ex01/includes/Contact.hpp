/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:18:50 by cahn              #+#    #+#             */
/*   Updated: 2023/11/04 17:19:24 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
        std::string getPhoneNumber();
        std::string getSecret();
        ~Contact();
};

#endif