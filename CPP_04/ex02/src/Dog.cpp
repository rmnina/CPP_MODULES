/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:06:10 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/24 18:26:17 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog( void) : AAnimal()
{
	std::cout << ITALIC BLUE << "Dog constructor called" << RESET << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->set_idea(&i, "Ouaf ouaf !!!");
}

Dog	&Dog::operator=( const Dog &rhs)
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

Dog::Dog( const Dog &src) : AAnimal( src)
{
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = new Brain(*src._brain);
		for (int i = 0; i < 100; i++)
			this->_brain->set_idea(&i, src._brain->get_idea(&i));
	}
}

std::string	Dog::getType( void) const
{
	return (this->_type);
}

void	Dog::set_idea( int *i, const std::string idea)
{
	this->_brain->set_idea(i, idea);
}

std::string	Dog::get_idea( int *i) const
{
	return (this->_brain->get_idea(i));
}

void	Dog::makeSound( void) const
{
	std::cout << BLUE << this->_type << " : Ouaf Ouaf !!" << RESET << std::endl;
}

Dog::~Dog( void)
{
	std::cout << ITALIC BLUE << "Dog destructor called" << RESET << std::endl;
	delete this->_brain;
}