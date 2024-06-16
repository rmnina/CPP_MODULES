/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:41:49 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/16 20:28:18 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string name, unsigned int grade) : _name(name), _grade(grade)
{
	std::cout << "Assignment operator called" << std::endl;
	try
	{
		if (this->_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (this->_grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
		this->_grade = 150;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
		this->_grade = 150;
	}
}

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat &rhs)
{
	this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::Bureaucrat( const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	std::cout << "Copy constructor called" << std::endl;
}

std::string	Bureaucrat::getName( void) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade( void) const
{
	return (this->_grade);
}

void	Bureaucrat::promote( void)
{
	try
	{
		if (this->_grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade--;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::demote( void)
{
	try
	{
		if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade++;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

const char	*Bureaucrat::GradeTooHighException::what( void) const throw()
{
	return ("Exception caught : Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what( void) const throw()
{
	return ("Exception caught : Grade too low");
}

Bureaucrat::~Bureaucrat( void)
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &rhs)
{
	os << rhs.getName();
	os << ", bureaucrat grade ";
	os << rhs.getGrade();
	return (os);
}