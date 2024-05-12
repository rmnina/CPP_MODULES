/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:25:05 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/12 21:30:42 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <string>
# include <iostream>
# include <cmath>
# include "Fixed.hpp"

# define GREEN	"\x1b[32m"
# define RED	"\x1b[31m"
# define BOLD	"\x1b[1m"
# define RESET	"\x1b[0m"

class Point
{
	
private:
	Fixed	_x;
	Fixed	_y;

public:
	Point( void);
	Point( const float a, const float b);
	Point( const Point &rhs);

	Fixed	get_x( void) const;
	Fixed	get_y( void) const;

	Point	& operator=( Point const &rhs);
	
	~Point( void);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif