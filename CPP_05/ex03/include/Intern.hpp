/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:45:23 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/02 17:22:40 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iomanip>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "new"

class Intern
{
	public:
		Intern( void);
		Intern( const Intern &src);
		Intern	&operator=( const Intern &rhs);

		AForm	*makeForm( const std::string name, const std::string target);

		class FormDoesNotExistException : public std::exception
		{
			public:
				virtual const char	*what( void) const throw();
		};
		
		~Intern( void);
};

AForm	*verifNew( const std::string name, const std::string target);

#endif