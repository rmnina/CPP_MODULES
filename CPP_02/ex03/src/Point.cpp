/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:25:30 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/12 21:30:57 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point( void)
{
	this->_x = 0;
	this->_y = 0;
}

Point::Point( const float a, const float b)
{
	this->_x = a;
	this->_y = b;
}

Point::Point( const Point &rhs)
{
	*this = rhs;
}

Fixed	Point::get_x( void) const
{
	return (this->_x);
}

Fixed	Point::get_y( void) const
{
	return (this->_y);
}

Point	& Point::operator=( Point const &rhs)
{
	this->_x = rhs._x;
	this->_y = rhs._y;
	return (*this);
}

Point::~Point( void)
{
	
}