/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:08:19 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/11 18:16:47 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <string>
# include <iostream>

template <typename T>
T min(const T &a, const T &b)
{
	return (a < b ? a : b);	
}

template <typename T>
T max(const T &a, const T &b)
{
	return (a > b ? a : b);
};

template <typename T>
void swap(T &a, T &b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

#endif