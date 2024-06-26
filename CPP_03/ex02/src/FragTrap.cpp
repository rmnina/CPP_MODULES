/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:36:24 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/13 00:56:03 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap( void) : ClapTrap()
{
	std::cout << BOLD TURQUOISE ITALIC << "FragTrap" << RESET << ITALIC << " defaut constructor called" << RESET << std::endl;
	this->_name = "noname";
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap( std::string name) : ClapTrap( name)
{
	std::cout << BOLD TURQUOISE ITALIC << "FragTrap" << RESET << ITALIC << " name constructor called" << RESET << std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap( FragTrap const &src) : ClapTrap( src)
{
	std::cout << BOLD TURQUOISE ITALIC << "FragTrap" << RESET << ITALIC << " copy constructor called" << RESET << std::endl;
	*this = src;
}

void	FragTrap::highFivesGuys( void)
{
	std::cout << BOLD PURPLE << _name << " requests to do a high five !" << RESET << std::endl;
}

void    FragTrap::get_highFives( void)
{
    this->highFivesGuys();
}

void    FragTrap::attack( const std::string &target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << "FragTrap " << BOLD << this->_name << RED << " attacks ";
		std::cout << RESET << BOLD << target << RESET << ", causing " << BOLD;
		std::cout << this->_attack_damage << RESET << " points of damage!" << std::endl;
		this->_energy_points--;
	}
	else if (this->_energy_points <= 0 && this->_hit_points > 0)
		std::cout << BOLD << this->_name << " tried to attack " << target << ", but has no energy left..." << RESET << std::endl;
	else
		std::cout << BOLD << this->_name << " are dead, they cannot attack " << target << " :(" << RESET << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &rhs)
{
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_attack_damage = rhs._attack_damage;
	this->_energy_points = rhs._energy_points;
	return (*this);
}

FragTrap::~FragTrap( void)
{
	std::cout << BOLD TURQUOISE ITALIC << "FragTrap" << RESET << ITALIC << " destructor called" << RESET << std::endl;
}