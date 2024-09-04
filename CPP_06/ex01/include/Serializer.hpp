/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:33:50 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/04 17:53:48 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <iostream>

typedef struct 
{
	int			i;
	char		c;
	float		f;
	std::string	info;
}	Data;

class Serializer
{
	private:
		Serializer( void);
		Serializer( const Serializer &src);
		Serializer	&operator=( const Serializer &rhs);
		~Serializer( void);

	public:
		static __intptr_t	serialize(Data *ptr);
		static Data			*deserialize(__intptr_t *raw);
};

#endif