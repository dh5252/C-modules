/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:22:47 by cahn              #+#    #+#             */
/*   Updated: 2023/11/11 17:02:52 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &w) : weapon(w), name(n)
{
}

void HumanA::setName(std::string str)
{
    name = str;
}
std::string HumanA::getName()
{
    return name;
}

void HumanA::attack()
{
    std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}