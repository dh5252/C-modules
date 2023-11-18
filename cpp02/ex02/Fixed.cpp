/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiwon <chiwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:24:40 by chiwon            #+#    #+#             */
/*   Updated: 2023/11/18 17:32:20 by chiwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
}

Fixed::Fixed(int num)
{
    value = (num << bits);
}

Fixed::Fixed(float num)
{
    value = roundf(num * (1 << bits));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &obj)
{
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

bool Fixed::operator>(Fixed const &ref) const
{
    return (this->getRawBits() > ref.getRawBits());
}

bool Fixed::operator<(Fixed const &ref) const
{
    return (this->getRawBits() < ref.getRawBits());
}


bool Fixed::operator>=(Fixed const &ref) const
{
    return (this->getRawBits() >= ref.getRawBits());
}

bool Fixed::operator<=(Fixed const &ref) const
{
    return (this->getRawBits() <= ref.getRawBits());
}

bool Fixed::operator==(Fixed const &ref) const
{
    return (this->getRawBits() == ref.getRawBits());
}

bool Fixed::operator!=(Fixed const &ref) const
{
    return (this->getRawBits() != ref.getRawBits());
}

Fixed Fixed::operator+(Fixed const &ref) const
{
    Fixed ret(this->toFloat() + ref.toFloat());
    return ret;
}

Fixed Fixed::operator-(Fixed const &ref) const
{
    Fixed ret(this->toFloat() - ref.toFloat());
    return ret;
}

Fixed Fixed::operator*(Fixed const &ref) const
{
    Fixed ret(this->toFloat() * ref.toFloat());
    return ret;
}

Fixed Fixed::operator/(Fixed const &ref) const
{
    Fixed ret(this->toFloat() / ref.toFloat());
    return ret;
}

Fixed& Fixed::operator++()
{
    this->value++;
    return *this;
}

Fixed& Fixed::operator--()
{
    this->value--;
    return *this;
}

const Fixed Fixed::operator++(int)
{
    const Fixed result(*this);
    this->value++;
    return (result);
}

const Fixed Fixed::operator--(int)
{
    const Fixed result(*this);
    this->value--;
    return (result);
}

Fixed& Fixed::min(Fixed &ref1, Fixed &ref2)
{
    if (ref1 < ref2)
        return ref1;
    return ref2;
}

Fixed& Fixed::max(Fixed &ref1, Fixed &ref2)
{
    if (ref1 > ref2)
        return ref1;
    return ref2;
}

const Fixed& Fixed::min(Fixed const &ref1, Fixed const &ref2)
{
    if (ref1 < ref2)
        return ref1;
    return ref2;
}

const Fixed& Fixed::max(Fixed const &ref1, Fixed const &ref2)
{
    if (ref1 > ref2)
        return ref1;
    return ref2;
}
       