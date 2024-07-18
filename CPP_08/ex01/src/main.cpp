/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:38:44 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/19 00:05:42 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

int main()
{
	std::cout << RED BOLD << "Subject tests" << RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span : " << sp.longestSpan() << std::endl;

	std::cout << std::endl << RED BOLD << "Insert and error tests" << RESET << std::endl;
	std::cout << ITALIC ORANGE << "Trying to add a value to the full container" << RESET << std::endl;
	try
	{
		sp.addNumber(12);
	}
	catch(const std::logic_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Span 			array = Span(10);
	unsigned int	src[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	std::cout << ITALIC ORANGE << "Trying to insert a range of values bigger than the destination's size" << RESET << std::endl;
	try
	{
		array.insert(src, 11);
	}
	catch(const std::logic_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << ITALIC ORANGE << "Finally adding a range of values" << RESET << std::endl;
	try
	{
		array.insert(src, 10);
	}
	catch(const std::logic_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << BLUE << "Array = ";
	for (int i = 0; i < 10; i++)
		std::cout << array.getNumber(i) << ", ";
	std::cout << RESET << std::endl << std::endl;

	std::cout << RED BOLD << "Trying with an enooormous array" << RESET << std::endl;
	Span	big = Span(20000);
	for (int i = 0; i < 20000; i++)
		big.addNumber(i);
	std::cout << BLUE << "Array = ";
	for (int i = 0; i < 20000; i++)
		std::cout << big.getNumber(i) << ", ";
	std::cout << RESET << std::endl;
	std::cout << "Shortest span : " << big.shortestSpan() << std::endl;
	std::cout << "Longest span : " << big.longestSpan() << std::endl;
	return (0);
}