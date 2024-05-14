/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 03:02:43 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/14 03:03:57 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <string>
# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

public:

	WrongCat( void);
	WrongCat( const WrongCat &src);
	
	void		makeSound( void) const;
	std::string	getType( void) const;
	
	WrongCat	&operator=( const WrongCat &rhs);

	~WrongCat( void);

};

#endif