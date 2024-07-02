/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:48:09 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/01 23:06:20 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;
	
	public:
		Form( void);
		Form( const std::string name, const unsigned int signGrade, const unsigned int execGrade);
		Form( const Form &src);
		Form	&operator=( const Form &rhs);

		std::string		getName( void) const;
		bool			getSigned( void) const;
		unsigned int	getSignGrade( void) const;
		unsigned int	getExecGrade( void) const;
		void			beSigned( const Bureaucrat &b);
		
		void			setSigned( bool signature);
	
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what( void) const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what( void) const throw();
		};

		~Form( void);
};

std::ostream	&operator<<(std::ostream &os, Form const &rhs);

#endif