/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:06:10 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/16 21:25:55 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog( void) : Animal()
{
	std::cout << ITALIC BLUE << "Dog constructor called" << RESET << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->set_idea(&i, "Ouaf ouaf !!!");
}

Dog::Dog( const Dog &src) : Animal( src)
{
	*this = src;
}

Dog	&Dog::operator=( const Dog &rhs)
{
	this->_type = rhs._type;
	this->_brain = rhs._brain;
	for (int i = 0; i < 100; i++)
		this->_brain->set_idea(&i, rhs._brain->get_idea(&i));
	return (*this);
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