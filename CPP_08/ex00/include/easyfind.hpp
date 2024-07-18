/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:13:34 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/18 20:26:02 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>

template <typename T>
typename T::const_iterator	easyfind(T container, int value)
{
	typename T::const_iterator res;
	res = std::find(container.begin(), container.end(), value);
	if (res != container.end())
		return (res);
	throw(std::logic_error("Bad occurence : not found"));
}

#endif