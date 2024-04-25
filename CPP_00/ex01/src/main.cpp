/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:02:27 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/26 00:50:38 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"
#include <string>
#include <iostream>

void	add_contact(PhoneBook *phonebook, int *i)
{
	phonebook->contacts[*i].fill_contact();
	(*i)++;
}

int main(void)
{
	PhoneBook   phonebook;
	std::string request;
	int			i;
	
	i = 0;
	do
	{
		std::cout << "Phonebook > ";
		std::getline(std::cin, request);
		if (!request.compare("SEARCH"))
			std::cout << "not found..." << std::endl;
		else if (!request.compare("ADD"))
			add_contact(&phonebook, &i);
		else if (!request.compare("EXIT"))
			break;
	} while (request.compare("EXIT"));
	return (0);
}