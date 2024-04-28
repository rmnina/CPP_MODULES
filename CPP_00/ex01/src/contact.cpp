/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:02:18 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/28 19:26:21 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"
#include <string>
#include <iomanip>

void	Contact::get_contact()
{
	if (_first_name.empty())
	{
		std::cout << "No contact at this index. Back to main menu..." << std::endl;
		return;
	}
	std::cout << "First name : " << _first_name << std::endl;
	std::cout << "Last name : " << _last_name << std::endl;
	std::cout << "Nickname : " << _nickname << std::endl;
	std::cout << "Phone number : " << _phone_number << std::endl;
	std::cout << "Deepest darkest secret : " << _secret << std::endl;
	return;
}

int	Contact::add_data(std::string display, std::string *field)
{
	std::string	info;
	
	while (!info.size())
	{
		std::cout << display;
		std::getline(std::cin, info);
		if (std::cin.eof())
			return (1);
		if (!display.compare("Phone number : "))
		{
			for (int i = 0; info[i]; i++)
				if (!std::isdigit(info[i]))
				{
					std::cout << "Numerical values expected" << std::endl;
					info.clear();
					break;
				}
		}
	}
	field->assign(info);
	return (0);
}

void	Contact::reset_contact(void)
{
	this->_first_name.erase(0, _first_name.size());
	this->_last_name.erase(0, _last_name.size());
	this->_nickname.erase(0, _nickname.size());
	this->_phone_number.erase(0, _phone_number.size());
	this->_secret.erase(0, _secret.size());
}

int	Contact::fill_contact(void)
{
	std::string	info;
	
	if (add_data("First name : ", &_first_name))
		return (1);
	if (add_data("Last name : ", &_last_name))
		return (1);
	if (add_data("Nickname : ", &_nickname))
		return (1);
	if (add_data("Phone number : ", &_phone_number))
		return (1);
	if (add_data("Deepest darkest secret : ", &_secret))
		return (1);
	return (0);
}

void	Contact::get_list_info()
{
	if (_first_name.size() > 8)
		std::cout << " " << _first_name.substr(0, 6) << ". |";
	else
	{
		std::cout << std::setw(8) << std::right;
		std::cout << _first_name << " |";
	}
	if (_last_name.size() > 8)
		std::cout << " " << _last_name.substr(0, 6) << ". |";
	else
	{
		std::cout << std::setw(8) << std::right;
		std::cout << _last_name << " |";
	}
	if (_phone_number.size() > 9)
		std::cout << " " << _phone_number.substr(0, 8) << "." << std::endl;
	else
	{
		std::cout << std::setw(10) << std::right;
		std::cout << _phone_number << std::endl;
	}
	return;
}