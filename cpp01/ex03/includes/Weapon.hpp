/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:15:41 by cahn              #+#    #+#             */
/*   Updated: 2023/11/11 16:46:10 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>

class Weapon {
    private:
        std::string type;
    public:
        std::string getType();
        void setType(std::string str);
        Weapon(std::string t);
        Weapon();
};

#endif