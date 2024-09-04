/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:42:43 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/04 21:07:53 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <string>
# include <iostream>
# include <ctime>
# include <exception>
# include <typeinfo>

class Base
{
	public:
		virtual ~Base( void);
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif