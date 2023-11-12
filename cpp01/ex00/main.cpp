/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:34:34 by cahn              #+#    #+#             */
/*   Updated: 2023/11/12 17:31:43 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Zombie.hpp"

int main(void)
{
    Zombie *dynamic = newZombie("heap");
    Zombie normalAlloc("stack");

    normalAlloc.announce();
    dynamic->announce();
    randomChump("stack2");
    delete dynamic;
    return 0;
}