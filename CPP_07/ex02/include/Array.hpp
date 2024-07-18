/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:57:37 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/18 17:08:51 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <iostream>
# include <exception>

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

template <typename T>
class Array
{
	private:
		T	*_array;
		int	_size;

	public:
		Array( void);
		Array( unsigned int n);
		Array( const Array<T> &src);
		
		Array<T>	&operator=( const Array<T> &rhs);
		T			&operator[]( const int index);

		const int	&size( void) const;

		class OutOfRangeException : public std::exception
		{
			public:
				const char	*what( void) const throw();
		};

		~Array( void);
};


#endif