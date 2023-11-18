/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiwon <chiwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:14:40 by chiwon            #+#    #+#             */
/*   Updated: 2023/11/18 17:31:00 by chiwon           ###   ########.fr       */
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
        bool operator>(Fixed const &ref) const;
        bool operator<(Fixed const &ref) const;
        bool operator>=(Fixed const &ref) const;
        bool operator<=(Fixed const &ref) const;
        bool operator==(Fixed const &ref) const;
        bool operator!=(Fixed const &ref) const;
        Fixed operator+(Fixed const &ref) const;
        Fixed operator-(Fixed const &ref) const;
        Fixed operator*(Fixed const &ref) const;
        Fixed operator/(Fixed const &ref) const;
        Fixed& operator++();
        const Fixed operator++(int);
        Fixed& operator--();
        const Fixed operator--(int);
        static Fixed& min(Fixed &ref1, Fixed &ref2);
        static Fixed& max(Fixed &ref1, Fixed &ref2);
        static const Fixed& min(Fixed const &ref1, Fixed const &ref2);
        static const Fixed& max(Fixed const &ref1, Fixed const &ref2);

        float toFloat() const;
        int toInt() const;
        int getRawBits() const;
        void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
