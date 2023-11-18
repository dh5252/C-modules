/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiwon <chiwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:14:40 by chiwon            #+#    #+#             */
/*   Updated: 2023/11/18 14:42:44 by chiwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    private :
        int                 value;
        const static int    bits = 8;
    public :
        Fixed();
        ~Fixed();
        Fixed(const Fixed &cp);
        Fixed& operator=(const Fixed &obj);
        int getRawBits() const;
        void setRawBits(int const raw);
};

#endif
