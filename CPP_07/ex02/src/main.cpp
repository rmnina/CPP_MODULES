/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:21:50 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/18 17:55:32 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"
#include "Array.cpp"

int main(int, char**)
{
	std::cout << RED BOLD<< "Preliminary tests : " << RESET RED ITALIC << std::endl << std::endl;
	Array<int>	numbers(10);
	Array<float> src(5);
	Array<float> dest;

	// Verifiying filling
	for (int i = 0; i < 10; i++)
		numbers[i] = i;

	// Verifying copy
	std::cout << std::endl << RESET ITALIC RED << "Verifying copy operator..." << std::endl;
	Array<int>	numbers_copy = Array<int>(numbers);
	for (int i = 0; i < 10; i++)
		std::cout << RESET PURPLE << "number " << i << " = " << numbers[i] << " ; ";
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << RESET YELLOW << "numbers_copy " << i << " = " << numbers_copy[i] << " ; ";

	std::cout << std::endl << RESET RED ITALIC << "Modifying src..." << std::endl;
	for (int i = 0; i < 10; i++)
		numbers[i] = 42;
	for (int i = 0; i < 10; i++)
		std::cout << RESET PURPLE << "number " << i << " = " << numbers[i] << " ; ";
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << RESET YELLOW << "numbers_copy " << i << " = " << numbers_copy[i] << " ; ";
	std::cout << std::endl << std::endl;
	
	// Verifying assignation
	std::cout << RESET ITALIC RED << "Verifying assignation operator..." << std::endl;
	for (int i = 0; i < 5; i++)
		src[i] = i + 0.5;
	dest = src;
	for (int i = 0; i < 5; i++)
		std::cout << RESET YELLOW << "src " << i << " = " << src[i] << " ; ";
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << RESET PURPLE << "dest " << i << " = " << dest[i] << " ; ";
	
	std::cout << std::endl << RESET RED ITALIC << "Modifying src..." << std::endl;
	for (int i = 0; i < 5; i++)
		src[i] = 42;
	for (int i = 0; i < 5; i++)
		std::cout << RESET PURPLE << "src " << i << " = " << src[i] << " ; ";
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << RESET YELLOW << "dest " << i << " = " << dest[i] << " ; ";
	std::cout << std::endl << std::endl;

	// Verifying member functions and exceptions
	std::cout << RED BOLD << "Verifying member functions and exceptions : " << RESET RED ITALIC << std::endl;
	Array<char>	letters(10);
	std::cout << std::endl << RESET PINK << "LETTERS _SIZE = " << letters.size() << std::endl;

	char c = 'a';
	for (int i = 0; i < 10; i++)
	{
		letters[i] = c;
		c++;
	}
	for (int i = 0; i < 10; i++)
		std::cout << RESET PINK << "letter " << i << " = " << letters[i] << " ; ";
	std::cout << std::endl << std::endl;
	
	try
	{
		letters[1] = 'u';
		std::cout << RESET BLUE << "letter 1 = " << letters[1] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		letters[42] = 'u';
		std::cout << RESET BLUE << "letter 1 = " << letters[42] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}