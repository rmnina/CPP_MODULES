/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:18:16 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/11 18:31:54 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <string>
# include <iostream>

template <typename T, typename Func>
void iter(T *array, size_t size, Func function)
{
	for (size_t i = 0; i < size; i++)
		function(array[i]);
}

template <typename T>
void	print(T &value) 
{
	std::cout << value << " ";
}

#endif