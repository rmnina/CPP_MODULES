/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:05:27 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/26 12:45:05 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP


# include <string>
# include <iostream>
# include "Animal.hpp"

class Dog : public Animal 
{

public:

	Dog( void);
	Dog( const Dog &src);
	
	void		makeSound( void) const;
	std::string	getType( void) const;
	void		setType( std::string type);

	Dog	&operator=( const Dog &rhs);

	~Dog( void);

};


#endif