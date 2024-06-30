/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:31:47 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/29 22:43:11 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"

Ice::Ice( void) : AMateria("ice"), _type("ice") {}

Ice    &Ice::operator=( const Ice &rhs)
{
    this->_type = rhs._type;
    return (*this);
}

Ice::Ice( const Ice &src) : AMateria(src)
{
    *this = src;
}

void    Ice::use( ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}

AMateria    *Ice::clone( void) const
{
    Ice *cpy = new Ice( *this);
    return (cpy);
}

Ice::~Ice( void) {}