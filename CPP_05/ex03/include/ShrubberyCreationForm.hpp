/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:50:06 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/01 23:13:47 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include <fstream>
# include <iomanip>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm( void);
		ShrubberyCreationForm( const std::string target);
		ShrubberyCreationForm( const ShrubberyCreationForm &src);
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &rhs);

		void	exec( void) const;

		~ShrubberyCreationForm( void);
};

#endif