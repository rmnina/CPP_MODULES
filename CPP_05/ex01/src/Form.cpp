/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:08:25 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/01 23:06:12 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form( void) : _name("default"), _signGrade(150), _execGrade(150) 
{
	_signed = false;
}

Form::Form( const std::string name, const unsigned int signGrade, const unsigned int execGrade) 
:_name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	_signed = false;
	try
	{
		if (_signGrade > 150 || _execGrade > 150)
			throw Form::GradeTooLowException();
		else if (_signGrade < 1 || _execGrade < 1)
			throw Form::GradeTooLowException();	
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Form::Form( const Form &src) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._signGrade)
{
	this->_signed= src._signed;	
}

Form	&Form::operator=( const Form &rhs)
{
	this->_signed = rhs._signed;
	return (*this);
}

std::string	Form::getName( void) const
{
	return (this->_name);
}

bool	Form::getSigned( void) const
{
	return (this->_signed);
}

unsigned int	Form::getSignGrade( void) const
{
	return (this->_signGrade);
}

unsigned int	Form::getExecGrade( void) const
{
	return (this->_execGrade);
}

void	Form::beSigned( const Bureaucrat &b)
{
	try
	{
		if (b.getGrade() > this->_signGrade || b.getGrade() > 150)
			throw Form::GradeTooLowException();
		else if (b.getGrade() < 1)
			throw Form::GradeTooHighException();
		else
			_signed = true;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cerr << "from Form::beSigned : " << e.what() << std::endl;
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cerr << "from Form::beSigned : " << e.what() << std::endl;
	}
}

void	Form::setSigned( bool signature)
{
	_signed = signature;
}

const char	*Form::GradeTooLowException::what( void) const throw()
{
	return ("Exception caught : grade too low");
}

const char	*Form::GradeTooHighException::what( void) const throw()
{
	return ("Exception caught : grade too high");
}

Form::~Form( void) {}

std::ostream	&operator<<(std::ostream &os, const Form &rhs)
{
	os << "Form " << rhs.getName() << ", min grade for signature " << rhs.getSignGrade();
	os << ", min grade for execution " << rhs.getExecGrade();
	if (rhs.getSigned())
		os << ", is signed." << std::endl;
	else
		os << ", is not signed." << std::endl;
	return (os);
}