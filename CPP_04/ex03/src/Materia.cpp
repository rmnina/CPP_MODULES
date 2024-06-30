/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:22:56 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/29 23:13:45 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Materia.hpp"

AMateria::AMateria( void) : _type("default") {}

AMateria::AMateria( const std::string &type) : _type(type) {}

AMateria::AMateria( const AMateria &src) : _type(src._type) {}

AMateria	&AMateria::operator=( const AMateria &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

const std::string	&AMateria::getType( void) const
{
	return (this->_type);
}

void	AMateria::use( ICharacter &target)
{
	std::cout << "Unknown Materia is being used on " << target.getName() << " !" << std::endl;
}

AMateria::~AMateria( void) {}