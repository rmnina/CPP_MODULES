/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:45:33 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/25 00:52:01 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>
# include <exception>

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