/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:39:15 by cahn              #+#    #+#             */
/*   Updated: 2023/11/11 20:42:48 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl {
    private :
        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void );
    public :
        void    complain(std::string level);
};



#endif