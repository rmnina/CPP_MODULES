/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:06:03 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/26 14:45:06 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat( void) : Animal()
{
	std::cout << ITALIC ORANGE << "Cat constructor called" << RESET << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->set_idea(&i, "Miiiiaaoouuuuuuu");
}

Cat	&Cat::operator=( const Cat &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
		delete (this->_brain);
		this->_brain = new Brain(*rhs._brain);
		for (int i = 0; i < 100; i++)
			this->_brain->set_idea(&i, rhs._brain->get_idea(&i));
	}
	return (*this);
}

Cat::Cat( const Cat &src) : Animal( src)
{
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = new Brain(*src._brain);
		for (int i = 0; i < 100; i++)
			this->_brain->set_idea(&i, src._brain->get_idea(&i));
	}
}

std::string	Cat::getType( void) const
{
	return (this->_type);
}

void	Cat::set_idea( int *i, const std::string idea)
{
	this->_brain->set_idea(i, idea);
}

std::string	Cat::get_idea( int *i) const
{
	return (this->_brain->get_idea(i));
}

void	Cat::makeSound( void) const
{
	std::cout << ORANGE << this->_type << " : Miiiaaaouuuuuu" << RESET << std::endl;
}

Cat::~Cat( void)
{
	std::cout << ITALIC ORANGE << "Cat destructor called" << RESET << std::endl;
	delete this->_brain;
}