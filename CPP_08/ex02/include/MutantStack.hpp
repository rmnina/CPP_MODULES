/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 00:13:47 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/19 02:23:38 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <vector>
# include <list>

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

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
	MutantStack( void);
	MutantStack( const MutantStack<T, Container> &src);
	
	MutantStack<T, Container>	&operator=( const MutantStack<T, Container> &rhs);

	typedef typename MutantStack<T, Container>::stack::container_type::iterator iterator;
	iterator	begin( void)
	{
		return (this->c.begin());
	}
	iterator	end( void)
	{
		return (this->c.end());
	}
	~MutantStack( void);
};

# include "MutantStack.tpp"

#endif