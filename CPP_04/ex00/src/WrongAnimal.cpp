/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 03:04:06 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/14 03:04:39 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void)
{
	std::cout << ITALIC RED << "WrongAnimal constructor called" << RESET << std::endl;
	this->_type = "notype_wrong";
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

WrongAnimal::WrongAnimal( const WrongAnimal &src)
{
	*this = src;
}

std::string	WrongAnimal::getType( void) const
{
	return this->_type;
}

void	WrongAnimal::makeSound( void) const
{
	std::cout << RED << this->_type << " : Chaotic and undetermined animal noises" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal( void)
{
	std::cout << ITALIC RED << "WrongAnimal destructor called" << RESET << std::endl;
}