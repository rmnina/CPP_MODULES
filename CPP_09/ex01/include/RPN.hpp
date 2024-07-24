/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:45:33 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/25 00:59:59 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
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

class RPN
{
	private:
		std::stack<int>	_stack;

	public:
		RPN( void);
		RPN( const RPN &src);
		RPN	&operator=( const RPN &rhs);
		
		void	parse( const std::string args);
		void	compute( const char c);
		void	printVal( void);

		void	add( void);
		void	divide( void);
		void	substract( void);
		void	multiply( void);

		~RPN( void);
};

bool	isOperand( char c);

#endif