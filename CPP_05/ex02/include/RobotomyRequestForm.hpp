/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:10:35 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/02 15:41:35 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"
# include <ctime>

class AForm;

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:	
		RobotomyRequestForm( void);
		RobotomyRequestForm( const std::string target);
		RobotomyRequestForm( const RobotomyRequestForm &src);
		RobotomyRequestForm	&operator=( const RobotomyRequestForm &rhs);

		void	exec( void) const;
		
		class FailedToRobotomizeException : public std::exception
		{
			public:
				virtual const char	*what( void) const throw();
		};
		
		~RobotomyRequestForm( void);
};

#endif