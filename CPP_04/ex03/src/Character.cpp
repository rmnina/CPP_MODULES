/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:48:05 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/30 02:22:18 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

Character::Character( void) : _name("default")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

const std::string	&Character::getName( void) const
{
	return (this->_name);
}

void	Character::setName( const std::string name)
{
	this->_name = name;
}

Character::Character( std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character	&Character::operator=( const Character &rhs)
{
	this->_name = rhs._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		this->_inventory[i] = rhs._inventory[i];
	}
	return (*this);
}

void	Character::equip( AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip( int index)
{
	if (index >= 0 && index < 4)
		this->_inventory[index] = NULL;
}

void	Character::use( int index, ICharacter &target)
{
	if (this->_inventory[index] != NULL)
		this->_inventory[index]->use(target);
}

Character::Character( const Character &src)
{
	this->_name = src._name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = src._inventory[i];
}

Character::~Character( void)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}