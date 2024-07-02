/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:48:50 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/02 18:36:43 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern( void) {}

Intern::Intern( const Intern &src) 
{
	*this = src;
}

Intern	&Intern::operator=( const Intern &rhs) 
{
	(void)rhs;
	return (*this);
}

const char	*Intern::FormDoesNotExistException::what( void) const throw()
{
	return ("Exception caught : form does not exist");
}

AForm	*Intern::makeForm( const std::string name, const std::string target)
{
	int			i = 0;
	const char	*names_list[3] = {"Presidential Pardon Form", "Shrubbery Creation Form", "Robotomy Request Form"};
	
	while (i < 3 && name.compare(names_list[i]))
		i++;
	switch (i) 
	{
		case 0: 
		{
			try 
			{
				return (new PresidentialPardonForm(target));
			}
			catch (const std::bad_alloc &e) 
			{
				std::cerr << e.what() << std::endl;
				return (NULL);
			}
			break;
		}
		case 1: 
		{
			try
			{
				return (new ShrubberyCreationForm(target));
			}
			catch (const std::bad_alloc &e) 
			{
				std::cerr << e.what() << std::endl;
				return (NULL);
			}
			break;
		}
		case 2: 
		{
			try
			{
				return (new RobotomyRequestForm(target));
			}
			catch (const std::bad_alloc &e) 
			{
				std::cerr << e.what() << std::endl;
				return (NULL);
			}
			break;
		}
		default:
		{
			try
			{
				throw Intern::FormDoesNotExistException();
			}
			catch (const Intern::FormDoesNotExistException &e)
			{
				std::cerr << e.what() << std::endl;
				return (NULL);
			}
		}
	}
}

Intern::~Intern( void) {}