/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:25:38 by cahn              #+#    #+#             */
/*   Updated: 2023/11/11 14:56:00 by cahn             ###   ########.fr       */
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
        void setName(std::string name);
        std::string getName();
        Zombie(std::string name);
        Zombie();
        ~Zombie();
};

#endif