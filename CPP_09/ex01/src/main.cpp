/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:57:05 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/25 00:53:04 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

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