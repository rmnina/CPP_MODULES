/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:57:05 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/25 01:03:58 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << BOLD RED << "Error : RPN needs one argument." << std::endl;
		std::cerr << "Format : \"[digits] [operands] [digits] [operands] [...]\"." << std::endl << std::endl;
		std::cerr << RESET ITALIC BLUE << "You must provide " << BOLD << "n digits " << RESET ITALIC BLUE << "and " << BOLD << "n - 1 operands " << RESET ITALIC BLUE << "for the program to run." << std::endl;
		std::cerr << "Any other character than " << BOLD << "\"123456789+-/* \" " << RESET ITALIC BLUE << "is not accepted." << std::endl;
		std::cerr << "If you enter 2 or more digits together, " << BOLD << "they will be treated separatly. " << RESET ITALIC BLUE << "Ex : \"12 +\" will be treated as \"1 2 +\"." << RESET << std::endl;
		return (1);
	}
	RPN	test;
	try
	{
		test.parse(argv[1]);
		test.printVal();
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}