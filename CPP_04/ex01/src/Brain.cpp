/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 03:33:09 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/14 03:40:08 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain( void)
{
	std::cout << ITALIC << "Brain constructor called" << RESET << std::endl;
}

Brain::Brain( const Brain &src)
{
	*this = src;
}

Brain	&Brain::operator=( const Brain &rhs)
{
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}

Brain::~Brain( void)
{
	std::cout << ITALIC << "Brain destructor called" << std::endl;
}