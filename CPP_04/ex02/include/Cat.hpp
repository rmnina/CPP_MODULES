/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:05:24 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/16 21:32:55 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{

private:
	Brain	*_brain;

public:

	Cat( void);
	Cat( const Cat &src);
	
	void		makeSound( void) const;
	std::string	getType( void) const;
	void		set_idea( int *i, const std::string idea);
	std::string	get_idea( int *i) const;
	
	Cat	&operator=( const Cat &rhs);

	~Cat( void);

};

#endif