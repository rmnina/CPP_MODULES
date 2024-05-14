/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 03:05:38 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/14 03:06:05 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat( void) : WrongAnimal()
{
	std::cout << ITALIC GREEN << "WrongCat constructor called" << RESET << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat &src) : WrongAnimal( src)
{
	*this = src;
}

WrongCat	&WrongCat::operator=( const WrongCat &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

std::string	WrongCat::getType( void) const
{
	return (this->_type);
}

void	WrongCat::makeSound( void) const
{
	std::cout << GREEN << this->_type << " : Miiiaaaouuuuuu" << RESET << std::endl;
}

WrongCat::~WrongCat( void)
{
	std::cout << ITALIC GREEN << "WrongCat destructor called" << RESET << std::endl;
}