/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 02:51:31 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/29 03:27:51 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

void	Harl::complain(std::string level)
{
	typedef void	(Harl::*pf)();
	const char		*array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	pf tab[4] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	for (int i = 0; i < 4; i++)
	{
		if (level == array[i])
		{
			(this->*tab[i])();
			return;
		}
	}
	std::cout << "Invalid level. Now Harl complains about not knowing what to do.";
	std::cout << " Great." << std::endl;
}

void	Harl::_debug(void)
{
	std::cout << GREEN << "I love having extra bacon for my 7XL-double-cheese-triple";
	std::cout << "-pickle-special-ketchup burger. I really do !" << RESET << std::endl;
}

void	Harl::_info(void)
{
	std::cout << YELLOW << "I cannot believe adding extra bacon costs more money. You ";
	std::cout << "didn't put enough bacon in my burger ! If you did, I wouldn't";
	std::cout << " be asking for more !" << RESET << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << ORANGE << "I think I deserve to have some extra bacon for free. I've been";
	std::cout << " coming for years whereas you started working here since last ";
	std::cout << "month." << RESET << std::endl;

}

void	Harl::_error(void)
{
	std::cout << BOLD << RED << "This is unacceptable ! I want to speak to the manager now.";
	std::cout << RESET << std::endl;
}