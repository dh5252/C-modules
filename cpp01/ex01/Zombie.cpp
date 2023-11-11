/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:37:00 by cahn              #+#    #+#             */
/*   Updated: 2023/11/11 14:56:47 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Zombie.hpp"

void Zombie::announce()
{
    std::cout << name << " " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->name = name;
}

std::string Zombie::getName()
{
    return name;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}
Zombie::Zombie()
{
}
Zombie::~Zombie()
{
    std::cout << name << " is gone...." << std::endl;
}