/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 23:58:17 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/13 00:46:55 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap( void) : ClapTrap()
{
	std::cout << BOLD GREEN ITALIC << "ScavTrap" << RESET << ITALIC << " defaut constructor called" << RESET << std::endl;
	this->_name = "noname";
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap( std::string name) : ClapTrap( name)
{
	std::cout << BOLD GREEN ITALIC << "ScavTrap" << RESET << ITALIC << " name constructor called" << RESET << std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap( ScavTrap &src) : ClapTrap( src)
{
	std::cout << BOLD GREEN ITALIC << "ScavTrap" << RESET << ITALIC << " copy constructor called" << RESET << std::endl;
	*this = src;
}

void    ScavTrap::attack( const std::string &target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << "ScavTrap " << BOLD << this->_name << RED << " attacks ";
		std::cout << RESET << BOLD << target << RESET << ", causing " << BOLD;
		std::cout << this->_attack_damage << RESET << " points of damage!" << std::endl;
		this->_energy_points--;
	}
	else if (this->_energy_points <= 0 && this->_hit_points > 0)
		std::cout << BOLD << this->_name << " tried to attack " << target << ", but has no energy left..." << RESET << std::endl;
	else
		std::cout << BOLD << this->_name << " are dead, they cannot attack " << target << " :(" << RESET << std::endl;
}

void	ScavTrap::gardGate( void)
{
	std::cout << BOLD << ORANGE << "ScavTrap is now in Gate keeper mode." << RESET << std::endl;
}

void	ScavTrap::get_gardGate( void)
{
	this->gardGate();
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs)
{
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_attack_damage = rhs._attack_damage;
	this->_energy_points = rhs._energy_points;
	return (*this);
}

ScavTrap::~ScavTrap( void)
{
	std::cout << BOLD GREEN ITALIC << "ScavTrap" << RESET << ITALIC << " destructor called" << RESET << std::endl;
}