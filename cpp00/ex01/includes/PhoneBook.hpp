/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:18:54 by cahn              #+#    #+#             */
/*   Updated: 2023/11/04 17:19:24 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
        ~PhoneBook();
        void SEARCH();
        void ADD();
};

#endif