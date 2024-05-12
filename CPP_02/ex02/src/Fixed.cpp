/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:34:12 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/12 16:15:02 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed( void)
{
    this->_value = 0;
}

Fixed::Fixed( const Fixed &src)
{
    *this = src;
}

Fixed::Fixed( const int src)
{
    this->_value = roundf(src * (1 << this->_bits));
}

Fixed::Fixed( const float src)
{
    this->_value = roundf(src * (1 << this->_bits));
}

float   Fixed::toFloat( void) const
{
    return (float(this->_value) / float(1 << this->_bits));
}

int Fixed::toInt( void)const
{
    return (int(this->_value) / int(1 << this->_bits));
}

int Fixed::getRawBits( void) const
{
    return (this->_value);
}

Fixed    Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

Fixed    Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

Fixed    Fixed::min(Fixed const &a, Fixed const &b)
{
    return (a < b ? a : b);
}

Fixed    Fixed::max(Fixed const &a, Fixed const &b)
{
    return (a > b ? a : b);
}

Fixed & Fixed::operator=( Fixed const &src)
{
    this->_value = src.getRawBits();
    return (*this);
}

std::ostream & operator<<(std::ostream &os, const Fixed &src)
{
    os << src.toFloat();
    return (os);
}

Fixed Fixed::operator+( Fixed const &src)
{
    return (this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-( Fixed const &src)
{
    return (this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*( Fixed const &src)
{
    return (this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/( Fixed const &src)
{
    if (src.toFloat() != 0)
        return (this->toFloat() / src.toFloat());
    else
	{
        std::cerr << "Error : div by 0. Operation has failed" << std::endl;
		return (*this);
	}
}

bool Fixed::operator<( Fixed const &src) const
{
    return (this->_value < src._value);
}

bool Fixed::operator>( Fixed const &src) const
{
    return (this->_value > src._value);
}

bool Fixed::operator<=( Fixed const &src) const
{
    return (this->_value <= src._value);
}

bool Fixed::operator>=( Fixed const &src) const
{
    return (this->_value >= src._value);
}

bool Fixed::operator==( Fixed const &src) const
{
    return (this->_value == src._value);
}

bool Fixed::operator!=( Fixed const &src) const
{
    return (this->_value != src._value);
}

Fixed & Fixed::operator++( void)
{
    this->_value++;
    return (*this);
}

Fixed Fixed::operator++( int)
{
    Fixed   temp;
    
    temp = *this;
    ++this->_value;
    return (temp);
}

Fixed & Fixed::operator--( void)
{
    this->_value--;
    return (*this);
}

Fixed Fixed::operator--( int)
{
    Fixed   temp;
    
    temp = *this;
    --this->_value;
    return (temp);
}

Fixed::~Fixed()
{
	
}