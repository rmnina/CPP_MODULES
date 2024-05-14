/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:06:10 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/14 03:43:07 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog( void) : Animal()
{
	std::cout << ITALIC BLUE << "Dog constructor called" << RESET << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog( const Dog &src) : Animal( src)
{
	*this = src;
}

Dog	&Dog::operator=( const Dog &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

std::string	Dog::getType( void) const
{
	return (this->_type);
}

void	Dog::makeSound( void) const
{
	std::cout << BLUE << this->_type << " : Ouaf Ouaf !!" << RESET << std::endl;
}

Dog::~Dog( void)
{
	std::cout << ITALIC BLUE << "Dog destructor called" << RESET << std::endl;
	delete this->_brain;
}