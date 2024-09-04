/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:38:54 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/04 19:34:43 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

Serializer::Serializer( void) {}

Serializer::Serializer( const Serializer &src)
{
	*this = src;
}

Serializer	&Serializer::operator=( const Serializer &rhs)
{
	(void)rhs;
	return (*this);
}

__intptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<__intptr_t>(ptr));
}

Data	*Serializer::deserialize(__intptr_t *raw)
{
	return (reinterpret_cast<Data*>(*raw));
}

Serializer::~Serializer( void) {}

