/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:46:56 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/29 22:34:57 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include <iostream>
# include "Materia.hpp"

class Cure : public AMateria
{
	private:
		std::string	_type;
	
	
	public:
		Cure( void);
		Cure( const Cure &src);
		Cure	&operator=( const Cure &rhs);
	
		void		use(ICharacter &target);
		AMateria	*clone( void) const;
	
		~Cure( void);
};

#endif