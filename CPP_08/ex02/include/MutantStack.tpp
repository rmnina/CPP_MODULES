/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 01:38:42 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/19 02:17:30 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack( void) : std::stack<T, Container>() {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack( const MutantStack<T, Container> &src) : std::stack<T, Container>(src)
{
	*this = src;
}

template <typename T, typename Container>
MutantStack<T, Container>	&MutantStack<T, Container>::operator=( const MutantStack<T, Container> &rhs)
{
	std::stack<T, Container>::operator=(rhs);
	return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack( void) {};