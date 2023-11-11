/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:37:00 by cahn              #+#    #+#             */
/*   Updated: 2023/11/11 14:45:37 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Zombie.hpp"

void Zombie::announce()
{
    std::cout << name << " " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}
Zombie::~Zombie()
{
    std::cout << name << " is gone...." << std::endl;
}