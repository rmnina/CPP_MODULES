/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 02:51:07 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/29 03:29:09 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << GREEN << "DEBUG" << RESET << std::endl;
	harl.complain("DEBUG");
	std::cout << YELLOW << "INFO" << RESET << std::endl;
	harl.complain("INFO");
	std::cout << ORANGE << "WARNING" << RESET << std::endl;
	harl.complain("WARNING");
	std::cout << RED << BOLD << "ERROR" << RESET << std::endl;
	harl.complain("ERROR");
	return (0);
}