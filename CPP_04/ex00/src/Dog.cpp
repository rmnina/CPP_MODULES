/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:06:10 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/26 14:37:03 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog( void) : Animal()
{
	std::cout << ITALIC BLUE << "Dog constructor called" << RESET << std::endl;
	this->_type = "Dog";
}

Dog	&Dog::operator=( const Dog &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

Dog::Dog( const Dog &src) : Animal( src)
{
	*this = src;
}

std::string	Dog::getType( void) const
{
	return (this->_type);
}

void	Dog::setType( std::string type)
{
	this->_type = type;
}

void	Dog::makeSound( void) const
{
	std::cout << BLUE << this->_type << " : Ouaf Ouaf !!" << RESET << std::endl;
}

Dog::~Dog( void)
{
	std::cout << ITALIC BLUE << "Dog destructor called" << RESET << std::endl;
}