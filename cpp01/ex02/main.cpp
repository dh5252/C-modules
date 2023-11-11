/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:05:34 by cahn              #+#    #+#             */
/*   Updated: 2023/11/11 15:12:41 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Memory Address (str) : " << &str << std::endl;
    std::cout << "Memory Address (stringPTR) : " << stringPTR << std::endl;
    std::cout << "Memory Address (stringREF) : " << &stringREF << std::endl;

    std::cout << "Value (str) : " << str << std::endl;
    std::cout << "Value (stringPTR) : " << *stringPTR << std::endl;
    std::cout << "Value (stringREF) : " << stringREF << std::endl;
}