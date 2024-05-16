/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:05:45 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/14 03:22:19 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

AAnimal::AAnimal( void)
{
	std::cout << ITALIC YELLOW << "AAnimal constructor called" << RESET << std::endl;
	this->_type = "notype";
}

AAnimal::AAnimal( const AAnimal &src)
{
	*this = src;
}

AAnimal &AAnimal::operator=( const AAnimal &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

std::string	AAnimal::getType( void) const
{
	return this->_type;
}

void	AAnimal::makeSound( void) const
{
	std::cout << YELLOW << this->_type << " : Chaotic and undetermined Aanimal noises" << RESET << std::endl;
}

AAnimal::~AAnimal( void)
{
	std::cout << ITALIC YELLOW << "AAnimal destructor called" << RESET << std::endl;
}