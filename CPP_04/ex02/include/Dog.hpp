/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:05:27 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/16 21:33:01 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP


# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal 
{

private:
	Brain	*_brain;

public:

	Dog( void);
	Dog( const Dog &src);
	
	void		makeSound( void) const;
	std::string	getType( void) const;
	void		set_idea( int *i, const std::string idea);
	std::string	get_idea( int *i) const;

	Dog	&operator=( const Dog &rhs);

	~Dog( void);

};


#endif