/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:02:18 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/26 00:49:57 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::add_data(std::string display, std::string *field)
{
	std::string	info;

	std::cout << display;
	std::cin >> info;
	field->assign(info);
	return;
}

void	Contact::fill_contact(void)
{
	std::string	info;
	
	add_data("First name : ", &this->_first_name);
	add_data("Last name : ", &this->_last_name);
	add_data("Nickname : ", &this->_nickname);
	add_data("Phone number : ", &this->_phone_number);
	add_data("Deepest darkest secret : ", &this->_secret);
	return;
}