/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:27:14 by cahn              #+#    #+#             */
/*   Updated: 2023/11/11 17:01:50 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/HumanB.hpp"

HumanB::HumanB(std::string n)
{
    name = n;
}

void HumanB::setName(std::string str)
{
    name = str;
}
std::string HumanB::getName()
{
    return name;
}

void HumanB::attack()
{
    std::cout << name << " attacks with his " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &w)
{
    weapon = &w;
}