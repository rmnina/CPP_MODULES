/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:12:08 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/14 04:15:06 by jdufour          ###   ########.fr       */
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

Fixed & Fixed::operator=( Fixed const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}