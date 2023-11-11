/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:57:32 by cahn              #+#    #+#             */
/*   Updated: 2023/11/11 15:01:36 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *arr = new Zombie[N];
    for (int i = 0 ; i < N ; ++i)
        arr[i].setName(name);
    return arr;
}