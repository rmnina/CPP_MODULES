/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:30:03 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/29 22:42:24 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include <iostream>
# include "Materia.hpp"

class Ice : public AMateria
{
	private:
		std::string	_type;
	
	
	public:
		Ice( void);
		Ice( const Ice &src);
		Ice	&operator=(const Ice &rhs);
	
		void		use(ICharacter &target);
		AMateria	*clone( void) const;
	
		~Ice( void);
};

#endif