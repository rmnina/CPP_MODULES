/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:05:01 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/30 22:24:55 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void) : AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target) : AForm("shrubbery", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src) : AForm(src)
{
	this->_target = src._target;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm &rhs)
{
	this->_target = rhs._target;
	return (*this);
}

void	ShrubberyCreationForm::execute( const Bureaucrat &executor)
{
	std::string	filename = _target;
	filename.append("_shrubbery");
	std::ofstream file;
	try
	{
		file.open(filename);
	}
	catch (const std::ofstream::failure &e)
	{
		std::cerr << e.what() << '\n';
	}
	file << "ascii tree" << std::endl;
	file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm( void) {}