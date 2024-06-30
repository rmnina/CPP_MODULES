/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:49:39 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/29 23:20:45 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource( void)
{
	for (int i = 0; i < 4; i++)
		this->_save[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource &src)
{
	for (int i = 0; i < 4; i++)
	{
		this->_save[i] = src._save[i];
	}
}

MateriaSource	&MateriaSource::operator=( const MateriaSource &rhs)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_save[i] != NULL)
			delete this->_save[i];
		this->_save[i] = rhs._save[i];
	}
	return (*this);
}

void	MateriaSource::learnMateria( AMateria *src)
{
	for (int i = 0; i < 4; i++)
	{
		if (_save[i] == NULL)
		{
			_save[i] = src->clone();
			delete src;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria( std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_save[i]->getType() == type)
			return (_save[i]->clone());
	}
	return (0);
}

MateriaSource::~MateriaSource( void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_save != NULL)
			delete this->_save[i];
	}
}