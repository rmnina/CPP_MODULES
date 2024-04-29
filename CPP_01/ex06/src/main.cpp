/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 03:31:07 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/29 04:00:07 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int main(int argc, char **argv)
{
	Harl	harl;
	
	if (argc != 2)
	{
		std::cout << "Please enter a minimal level of complain : ";
		std::cout << "DEBUG, INFO, WARNING, ERROR" << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}