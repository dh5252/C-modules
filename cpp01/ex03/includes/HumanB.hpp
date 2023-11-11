/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:25:39 by cahn              #+#    #+#             */
/*   Updated: 2023/11/11 17:02:16 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
    private :
        Weapon *weapon;
        std::string name;
    public :
        HumanB(std::string n);
        void setName(std::string str);
        std::string getName();
        void setWeapon(Weapon &w);
        void attack();
};

#endif