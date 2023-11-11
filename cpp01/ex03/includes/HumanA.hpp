/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:19:27 by cahn              #+#    #+#             */
/*   Updated: 2023/11/11 17:02:20 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
    private :
        Weapon &weapon;
        std::string name;
    public :
        HumanA(std::string n, Weapon &w);
        void setName(std::string str);
        std::string getName();
        void attack();
};



#endif