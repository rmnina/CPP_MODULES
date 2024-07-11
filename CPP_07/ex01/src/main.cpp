/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:08:05 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/11 18:31:04 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

void	increment(int &value) 
{
	value += 1;
}

void	doubled(int &value)
{
	value *= 2;
}

int main( void ) 
{
	int		array[] = {1, 2, 3, 4, 5};
	size_t	size = 5;

	std::cout << "array values: ";
	iter(array, size, print<int>);
	std::cout << std::endl;

	iter(array, size, increment);
	std::cout << "values after increment: ";
	iter(array, size, print<int>);
	std::cout << std::endl;

	iter(array, size, doubled);
	std::cout << "values after being double: ";
	iter(array, size, print<int>);
	std::cout << std::endl;

	std::string	strArray[] = {"apple", "banana", "cherry"};
	size_t 		strSize = 3;

	std::cout << "string array: ";
	iter(strArray, strSize, print<std::string>);
	std::cout << std::endl;

	return (0);
}