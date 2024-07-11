/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:55:02 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/04 20:12:43 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/B.hpp"

B::B( void)
{
    _type = "B";
}

std::string	B::get_type( void)
{
	return _type;
}

B::~B( void) {}