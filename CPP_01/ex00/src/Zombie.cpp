/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:14:06 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/28 23:07:15 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << GREEN << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl << RESET;
}

Zombie::~Zombie(void)
{
	std::cout << RED << BOLD << this->_name << " has been destroyed..." << std::endl << RESET;
}