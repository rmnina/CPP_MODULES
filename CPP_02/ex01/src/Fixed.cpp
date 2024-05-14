/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:59:50 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/14 04:15:02 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed( void)
{
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}

Fixed::Fixed( const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed( const int src)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = roundf(src * (1 << this->_bits));
}

Fixed::Fixed( const float src)
{
    std::cout << "Float constructor called" << std::endl;
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

Fixed & Fixed::operator=( Fixed const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = rhs.getRawBits();
    return (*this);
}

std::ostream & operator<<(std::ostream &os, const Fixed &src)
{
    os << src.toFloat();
    return (os);
}

int Fixed::getRawBits( void) const
{
    return (this->_value);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}