/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:47:51 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/29 00:32:48 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;;
}

void	HumanB::setWeapon(Weapon weapon)
{
	*_weapon = weapon;
}

void	HumanB::attack(void)
{
	if (!this->_weapon)
        std::cout << BOLD << GREEN << this->_name << " attacks with their bare hands !" << RESET << std::endl;
    else
	    std::cout << BOLD << GREEN << this->_name << " attacks with " << this->_weapon->getType() << " !" << RESET << std::endl;
}