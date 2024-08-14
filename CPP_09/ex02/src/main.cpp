/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:25:06 by jdufour           #+#    #+#             */
/*   Updated: 2024/08/14 02:41:32 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PMergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << BOLD RED << "Error : numbers to sort must be passed as an argument" << RESET << std::endl;
		return (1);
	}
	try
	{
		PMergeMe	data(argv + 1);
		data.mergeInsert();
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << BOLD RED << e.what() << RESET << std::endl;
	}
	return (0);
}