/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:06:03 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/14 03:22:06 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat( void) : Animal()
{
	std::cout << ITALIC ORANGE << "Cat constructor called" << RESET << std::endl;
	this->_type = "Cat";
}

Cat	&Cat::operator=( const Cat &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

Cat::Cat( const Cat &src) : Animal( src)
{
	*this = src;
}

std::string	Cat::getType( void) const
{
	return (this->_type);
}

void	Cat::makeSound( void) const
{
	std::cout << ORANGE << this->_type << " : Miiiaaaouuuuuu" << RESET << std::endl;
}

Cat::~Cat( void)
{
	std::cout << ITALIC ORANGE << "Cat destructor called" << RESET << std::endl;
}