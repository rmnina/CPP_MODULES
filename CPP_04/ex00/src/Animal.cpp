/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:05:45 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/14 03:22:19 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal( void)
{
	std::cout << ITALIC YELLOW << "Animal constructor called" << RESET << std::endl;
	this->_type = "notype";
}

Animal::Animal( const Animal &src)
{
	*this = src;
}

Animal &Animal::operator=( const Animal &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

std::string	Animal::getType( void) const
{
	return this->_type;
}

void	Animal::makeSound( void) const
{
	std::cout << YELLOW << this->_type << " : Chaotic and undetermined animal noises" << RESET << std::endl;
}

Animal::~Animal( void)
{
	std::cout << ITALIC YELLOW << "Animal destructor called" << RESET << std::endl;
}