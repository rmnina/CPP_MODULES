/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:53:24 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/28 18:45:24 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iomanip>
#include <iostream>
#include "../include/phonebook.hpp"

void    PhoneBook::print_list(int *i)
{
	int	new_i;
	
	if (*i >= 8)
		new_i = 8;
	else
		new_i = *i;
	for (int j = 0; j < new_i; j++)
	{
		std::cout << std::setw(9) << std::right;
		std::cout << j + 1 << " |";
		contacts[j].get_list_info();
		std::setw(0);
	} 
}