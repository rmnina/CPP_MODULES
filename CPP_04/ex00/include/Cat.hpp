/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:05:24 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/14 02:49:16 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{

public:

	Cat( void);
	Cat( const Cat &src);
	
	void		makeSound( void) const;
	std::string	getType( void) const;
	
	Cat	&operator=( const Cat &rhs);

	~Cat( void);

};

#endif