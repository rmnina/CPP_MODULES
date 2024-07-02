/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:17:43 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/02 15:41:24 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void) : AForm(), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm( const std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src) : AForm( src)
{
	_target = src._target;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm &rhs)
{
	_target = rhs._target;
	return (*this);
}

const char	*RobotomyRequestForm::FailedToRobotomizeException::what( void) const throw()
{
	return ("Robotomy has failed :( Don't worry, it happens half ot the time");
}

void	RobotomyRequestForm::exec( void) const
{
	std::time_t time = std::time(NULL);
	std::tm	*localtime = std::localtime(&time);
	
	try
	{
		if (localtime->tm_sec % 2 == 0)
		{
			std::cout << "DRRRRRRRRRRRR" << std::endl;
			std::cout << _target << " has been robotomised successfully " << std::endl;
		}
		else
		{
			throw RobotomyRequestForm::FailedToRobotomizeException();
		}
	}
	catch (const RobotomyRequestForm::FailedToRobotomizeException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

RobotomyRequestForm::~RobotomyRequestForm( void) {}

