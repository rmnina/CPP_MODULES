/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:01:05 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/01 23:27:17 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void) : AForm(), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm( const std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src) : AForm(src), _target(src._target) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm &rhs)
{
	this->_target = rhs._target;
	return (*this);
}

void	PresidentialPardonForm::exec( void) const
{
		std::cout << _target << " has been forgived by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void) {}

