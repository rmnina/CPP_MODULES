/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 03:33:09 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/16 19:42:32 by jdufour          ###   ########.fr       */
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

void	Brain::set_idea(int *i, const std::string idea)
{
	this->_ideas[*i] = idea;
}

std::string	Brain::get_idea(int *i) const
{
	return (this->_ideas[*i]);
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