/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:19:00 by cahn              #+#    #+#             */
/*   Updated: 2023/11/04 17:19:24 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

int main()
{
    PhoneBook book;
    std::string cmd;

    std::cout << "Input command : ";
    while (std::cin >> cmd)
    {
        if (cmd == "ADD")
            book.ADD();
        else if (cmd == "SEARCH")
            book.SEARCH();
        else if (cmd == "EXIT")
            break;
        else
            std::cout << "Input correct command!\n";
        std::cout << "Input command : " << std::flush;
    }
}