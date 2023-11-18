/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiwon <chiwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:24:40 by chiwon            #+#    #+#             */
/*   Updated: 2023/11/18 15:08:14 by chiwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Defalut constructor called" << std::endl;
    value = 0;
}

Fixed::Fixed(int num)
{
    std::cout << "Int constructor called" << std::endl;
    value = (num << bits);
}

Fixed::Fixed(float num)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(num * (1 << bits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = obj.getRawBits();
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

float   Fixed::toFloat() const
{
    return ((float)value / (1 << bits));
}

int   Fixed::toInt() const
{
    return (value >> bits);
}

Fixed& Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &obj)
        return *this;
    value = obj.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}