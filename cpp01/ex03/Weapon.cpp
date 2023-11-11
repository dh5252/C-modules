/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:18:02 by cahn              #+#    #+#             */
/*   Updated: 2023/11/11 16:46:29 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Weapon.hpp"

void    Weapon::setType(std::string str)
{
    type = str;
}

std::string Weapon::getType()
{
    return type;
}

Weapon::Weapon(std::string t)
{
    type = t;
}

Weapon::Weapon()
{
}