/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:42:12 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/29 23:05:21 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOUCE_HPP

# include "Materia.hpp"
# include <iostream>
# include <string>

class IMateriaSource 
{
	public:
		virtual ~IMateriaSource( void) {}
		virtual void		learnMateria( AMateria *) = 0;
		virtual AMateria	*createMateria(std::string const &type) = 0;
};

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_save[4];

	public:
		MateriaSource( void);
		MateriaSource( const MateriaSource &src);
		MateriaSource	&operator=( const MateriaSource &rhs);

		void		learnMateria( AMateria *src);
		AMateria	*createMateria(std::string const &type);
		
		~MateriaSource( void);
};


#endif