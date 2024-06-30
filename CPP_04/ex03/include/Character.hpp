/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:08:28 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/29 23:26:57 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>
# include "Materia.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter( void) {}
		virtual std::string const	&getName( void) const = 0;
		virtual void				equip( AMateria *m) = 0;
		virtual void				unequip( int index) = 0;
		virtual void				use( int index, ICharacter &target) = 0;
};

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[4];
	
	public:
		Character( void);
		Character( const std::string name);
		Character( const Character &src);
		Character	&operator=( const Character &rhs);

		const std::string	&getName( void) const;
		void				setName( const std::string name);
		void				equip( AMateria *m);
		void				unequip( int index);
		void				use( int index, ICharacter &target);
		
		~Character( void);
};



#endif