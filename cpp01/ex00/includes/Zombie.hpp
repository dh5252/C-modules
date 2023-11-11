/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:25:38 by cahn              #+#    #+#             */
/*   Updated: 2023/11/11 14:41:38 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {
    private :
        std::string name;
    public :
        void announce();
        Zombie(std::string name);
        ~Zombie();
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);


#endif