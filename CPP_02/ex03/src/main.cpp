/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:34:36 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/12 21:45:31 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

int main( void ) 
{
	Point	a(5.64, -5.61);
	Point	b(6.26, -2.34);
	Point	c(1.7, -4.65);
	Point	point(4.12, -4.39);

	if (bsp(a, b, c, point))
		std::cout << "The point is " << BOLD << GREEN << "inside " << RESET << "the triangle." << std::endl;
	else
		std::cout << "The point is " << BOLD << RED << "outside " << RESET << "(or on) the triangle." << std::endl;
}

// https://www.geogebra.org/classic?lang=fr