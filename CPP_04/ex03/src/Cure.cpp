/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:26:59 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/29 22:44:15 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"

Cure::Cure( void) : AMateria("cure"), _type("cure") {}

Cure    &Cure::operator=( const Cure &rhs)
{
    this->_type = rhs._type;
    return (*this);
}

Cure::Cure( const Cure &src) : AMateria(src)
{
    *this = src;
}

void    Cure::use( ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria    *Cure::clone( void) const
{
    Cure *cpy = new Cure( *this);
    return (cpy);
}

Cure::~Cure( void) {}