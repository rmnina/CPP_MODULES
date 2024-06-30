/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 22:13:57 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/13 00:30:33 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap( void)
{
	std::cout << ITALIC << "ClapTrap default contructor called" << RESET << std::endl;
	this->_name = "noname";
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
}

ClapTrap::ClapTrap( const std::string name)
{
	std::cout << ITALIC << "ClapTrap name contructor called" << RESET << std::endl;
	this->_name = name;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << ITALIC << "ClapTrap copy contructor called" << RESET << std::endl;
	*this = src;
}

void    ClapTrap::attack( const std::string &target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << "ClapTrap " << BOLD << this->_name << RED << " attacks ";
		std::cout << RESET << BOLD << target << RESET << ", causing " << BOLD;
		std::cout << this->_attack_damage << RESET << " points of damage!" << std::endl;
		this->_energy_points--;
	}
	else if (this->_energy_points <= 0 && this->_hit_points > 0)
		std::cout << BOLD << this->_name << " tried to attack " << target << ", but has no energy left..." << RESET << std::endl;
	else
		std::cout << BOLD << this->_name << " are dead, they cannot attack " << target << " :(" << RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points <= 0)
		std::cout << BOLD << this->_name << " cannot take more damage, they are already dead..." << RESET << std::endl;
	else if (this->_hit_points > 0)
	{
		this->_hit_points -= amount;
		std::cout << "ClapTrap " << BOLD << this->_name << RESET << " took ";
		std::cout << BOLD << PINK << amount << RESET << PINK << " points of damage. ";
		if (this->_hit_points > 0)
			std::cout << RESET << BOLD << this->_hit_points << RESET << " hp left." << std::endl;
		else if (this->_hit_points <= 0)
			std::cout << RESET << BOLD << this->_name << RESET << " died..." << std::endl;	
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points <= 0)
		std::cout << BOLD << this->_name << " cannot be repaired, they are already dead..." << RESET << std::endl;
	else if (this->_energy_points <= 0)
		std::cout << BOLD << this->_name << " tried to be repaired, but has no energy left..." << RESET << std::endl;
	else
	{
		this->_hit_points += amount;
		std::cout << "ClapTrap " << BOLD << this->_name << RESET << BLUE << " regained " << BOLD << amount;
		std::cout << " hit points. " << RESET << BOLD << this->_hit_points << RESET << " hp left." << std::endl;
	}
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_attack_damage = rhs._attack_damage;
	this->_energy_points = rhs._energy_points;
	return (*this);
}

ClapTrap::~ClapTrap( void)
{
	std::cout << ITALIC << "Destructor called" << RESET << std::endl;
}