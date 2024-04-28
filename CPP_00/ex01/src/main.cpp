/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:02:27 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/28 19:21:12 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include "../include/phonebook.hpp"

int	add_contact(PhoneBook *phonebook, int *i)
{
	if (*i <= 8)
		phonebook->contacts[*i % 8].reset_contact();
	if (phonebook->contacts[*i % 8].fill_contact())
		return (1);
	(*i)++;
	return (0);
}

int	search_contact(PhoneBook *phonebook, int *i)
{
	std::string	index;
	int			j;
	
	if (*i == 0)
	{
		std::cout << "Contact list is empty" << std::endl;
		return (0);
	}
	phonebook->print_list(i);
	std::cout << "For more details about a contact, enter their index : ";
	if (!std::getline(std::cin, index))
		return (1);
	if (std::isdigit(index[0]) && index.size() == 1)
	{
		j = index[0] - 48;
		j--;
		if (j < 0 || (*i >= 8 && j > 7) || (*i < 8 && j > (*i % 8)))
			std::cout << "Invalid index. Back to main menu..." << std::endl;
		else
			phonebook->contacts[j].get_contact();
	}
	else
		std::cout << "Invalid index. Back to main menu..." << std::endl;
	return (0);
}

int main(void)
{
	PhoneBook   phonebook;
	std::string request;
	int			i;
	
	i = 0;
	std::cout << "Phonebook > ";
	do
	{
		if (!std::getline(std::cin, request))
			break;
		if (!request.compare("SEARCH"))
		{
			if (search_contact(&phonebook, &i))
			{
				std::cout << std::endl << "stdin reached EOF. Exiting..." << std::endl;
				break;
			}
		}
		else if (!request.compare("ADD"))
		{
			if (add_contact(&phonebook, &i))
			{
				std::cout << std::endl << "stdin reached EOF. Exiting..." << std::endl;
				break;
			}
		}
		else if (!request.compare("EXIT"))
			break;
		std::cout << "Phonebook > ";
	} while (request.compare("EXIT"));
	return (0);
}