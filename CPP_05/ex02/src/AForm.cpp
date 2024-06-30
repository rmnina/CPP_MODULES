/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:08:25 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/30 19:38:13 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm( void) : _name("default"), _signGrade(150), _execGrade(150) 
{
	_signed = false;
}

AForm::AForm( const std::string name, const unsigned int signGrade, const unsigned int execGrade) 
:_name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	_signed = false;
	try
	{
		if (_signGrade > 150 || _execGrade > 150)
			throw AForm::GradeTooLowException();
		else if (_signGrade < 1 || _execGrade < 1)
			throw AForm::GradeTooLowException();	
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const AForm::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

AForm::AForm( const AForm &src) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._signGrade)
{
	this->_signed= src._signed;	
}

AForm	&AForm::operator=( const AForm &rhs)
{
	this->_signed = rhs._signed;
	return (*this);
}

std::string	AForm::getName( void) const
{
	return (this->_name);
}

bool	AForm::getSigned( void) const
{
	return (this->_signed);
}

unsigned int	AForm::getSignGrade( void) const
{
	return (this->_signGrade);
}

unsigned int	AForm::getExecGrade( void) const
{
	return (this->_execGrade);
}

void	AForm::beSigned( const Bureaucrat *b)
{
	try
	{
		if (b->getGrade() > this->_signGrade || b->getGrade() > 150)
			throw AForm::GradeTooLowException();
		else if (b->getGrade() < 1)
			throw AForm::GradeTooHighException();
		else
			_signed = true;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "from AForm::beSigned : " << e.what() << std::endl;
	}
	catch (const AForm::GradeTooHighException &e)
	{
		std::cerr << "from AForm::beSigned : " << e.what() << std::endl;
	}
}

void	AForm::setSigned( bool signature)
{
	_signed = signature;
}

const char	*AForm::GradeTooLowException::what( void) const throw()
{
	return ("Exception caught : grade too low");
}

const char	*AForm::GradeTooHighException::what( void) const throw()
{
	return ("Exception caught : grade too high");
}

AForm::~AForm( void) {}

std::ostream	&operator<<(std::ostream &os, const AForm &rhs)
{
	os << "AForm " << rhs.getName() << ", min grade for signature " << rhs.getSignGrade();
	os << ", min grade for execution " << rhs.getExecGrade();
	if (rhs.getSigned())
		os << ", is signed." << std::endl;
	else
		os << ", is not signed." << std::endl;
	return (os);
}