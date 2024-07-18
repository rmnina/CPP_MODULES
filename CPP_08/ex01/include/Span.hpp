/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:54:39 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/19 00:04:13 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <string>
#include <iostream>
#include <exception>
#include <algorithm>
#include <cmath>

# define RED		"\x1b[31m"
# define BLUE		"\x1b[34m"
# define RESET		"\x1b[0m"
# define GREEN		"\x1b[32m"
# define PINK		"\x1b[95m"
# define YELLOW 	"\x1b[33m"
# define ORANGE 	"\x1b[38;5;208m"
# define PURPLE 	"\x1b[38;5;129m"
# define TURQUOISE	"\x1b[38;5;80m"
# define MAGENTA	"\x1b[35m"
# define BOLD		"\x1b[1m"
# define ITALIC		"\x1b[3m"

class Span
{
	private:
		unsigned int		*_array;
		unsigned int		_size;
		unsigned int		_capacity;

	public:
		Span( void);
		Span( const unsigned int N);
		Span( const Span &src);
		
		Span	&operator=( const Span &rhs);

		void			addNumber( const unsigned int value);
		unsigned int	getNumber( int index) const;
		void			insert( const unsigned int *src, const unsigned int size);
		unsigned int	shortestSpan( void) const;
		unsigned int	longestSpan( void) const;

		~Span( void);
};


#endif