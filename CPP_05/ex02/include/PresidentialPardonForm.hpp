/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:56:52 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/01 23:13:41 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <exception>
# include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm( void);
		PresidentialPardonForm( std::string target);
		PresidentialPardonForm( const PresidentialPardonForm &src);
		PresidentialPardonForm	&operator=( const PresidentialPardonForm &rhs);

		void	exec( void) const;

		~PresidentialPardonForm( void);
};

#endif