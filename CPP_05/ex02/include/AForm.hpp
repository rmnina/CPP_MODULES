/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:48:09 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/01 23:14:36 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;
	
	public:
		AForm( void);
		AForm( const std::string name, const unsigned int signGrade, const unsigned int execGrade);
		AForm( const AForm &src);
		AForm	&operator=( const AForm &rhs);

		std::string		getName( void) const;
		bool			getSigned( void) const;
		unsigned int	getSignGrade( void) const;
		unsigned int	getExecGrade( void) const;
		
		void			beSigned( const Bureaucrat &b);
		void			setSigned( bool signature);
		void			execute( Bureaucrat const &executor) const;
		virtual void	exec( void) const = 0;
	
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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char	*what( void) const throw();
		};
		
		virtual ~AForm( void);
};

std::ostream	&operator<<(std::ostream &os, AForm const &rhs);

#endif