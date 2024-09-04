/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:19:49 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/04 20:21:16 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"

int	main(void)
{
	Base	*baseptr = generate();
	Base	&baseref = *baseptr;

	identify(baseptr);
	identify(baseref);
	delete baseptr;
	return (0);
}