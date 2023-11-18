/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiwon <chiwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:14:40 by chiwon            #+#    #+#             */
/*   Updated: 2023/11/18 15:06:10 by chiwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private :
        int                 value;
        const static int    bits = 8;
    public :
        Fixed();
        Fixed(int num);
        Fixed(float num);
        ~Fixed();
        Fixed(const Fixed &cp);
        Fixed& operator=(const Fixed &obj);
        float toFloat() const;
        int toInt() const;
        int getRawBits() const;
        void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
