/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:05:24 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/14 03:41:44 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{

private:
	Brain	*_brain;

public:

	Cat( void);
	Cat( const Cat &src);
	
	void		makeSound( void) const;
	std::string	getType( void) const;
	
	Cat	&operator=( const Cat &rhs);

	~Cat( void);

};

#endif