/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:14:20 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/28 23:02:32 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie	*new_Zombie(std::string name)
{
	Zombie	*zombie;

	zombie = new Zombie;
	if (!zombie)
		return (NULL);
	zombie->set_name(name);
	return (zombie);
}