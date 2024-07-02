/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:21:35 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/01 23:08:32 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;

	public:
		Bureaucrat( void);
		Bureaucrat( const std::string name, unsigned int grade);
		Bureaucrat( const Bureaucrat &src);

		Bureaucrat  	&operator=( const Bureaucrat &rhs);

		std::string		getName( void) const;
		unsigned int	getGrade( void) const;
		void			promote( void);
		void			demote( void);
		void			signForm( AForm &f);
		void			executeForm( const AForm &f);

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what( void) const throw();
		};

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what( void) const throw();
		};
		
		~Bureaucrat( void);
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &rhs);

#endif