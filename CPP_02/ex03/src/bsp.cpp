/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:25:26 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/12 21:41:27 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Fixed     scalar(Point const a1, Point const a2, Point const point)
{
	Fixed	scal1;
	Fixed	scal2;

	scal1 = (a2.get_x() - point.get_x()) * (a1.get_y() - point.get_y());
	scal2 = (a2.get_y() - point.get_y()) * (a1.get_x() - point.get_x());
	return (scal1 - scal2);
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (scalar(a, b, point) > 0 && scalar(b, c, point) > 0 && scalar(c, a, point) > 0)
		return (true);
	if (scalar(a, b, point) < 0 && scalar (b, c, point) < 0 && scalar(c, a, point) < 0)
		return (true);
	else
		return (false);
}