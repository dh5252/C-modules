/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:34:34 by cahn              #+#    #+#             */
/*   Updated: 2023/11/12 17:43:46 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Zombie.hpp"

int main(void)
{
    Zombie *horde;

    horde = zombieHorde(5, "cahn");
    for (int i = 0 ; i < 5 ; ++i)
        horde[i].announce();
    delete[] horde;
    return 0;
}