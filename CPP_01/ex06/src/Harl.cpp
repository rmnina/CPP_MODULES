/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 03:31:04 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/29 04:05:58 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

void	Harl::complain(std::string level)
{
    typedef void	(Harl::*pf)();
	const char		*array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int             i;
	
    for (i = 0; i < 4; i++)
    {
        if (!level.compare(array[i]))
            break;
    }
	pf tab[4] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	switch (i)
	{
        case 0:
		    (this->*tab[0])();
            __attribute__((fallthrough));
        case 1:
            (this->*tab[1])();
            __attribute__((fallthrough));
        case 2:
            (this->*tab[2])();
            __attribute__((fallthrough));
        case 3:
            (this->*tab[3])();
            break;
        default:
           	std::cout << ITALIC << "[ Probably complaining about insignificant problems ]";
            std::cout << RESET << std::endl;
        
	}

}

void	Harl::_debug(void)
{
	std::cout << GREEN << "DEBUG" << RESET << std::endl;
    std::cout << GREEN << "I love having extra bacon for my 7XL-double-cheese-triple";
	std::cout << "-pickle-special-ketchup burger. I really do !" << RESET << std::endl;
}

void	Harl::_info(void)
{
	std::cout << YELLOW << "INFO" << RESET << std::endl;
    std::cout << YELLOW << "I cannot believe adding extra bacon costs more money. You ";
	std::cout << "didn't put enough bacon in my burger ! If you did, I wouldn't";
	std::cout << " be asking for more !" << RESET << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << ORANGE << "WARNING" << RESET << std::endl;
    std::cout << ORANGE << "I think I deserve to have some extra bacon for free. I've been";
	std::cout << " coming for years whereas you started working here since last ";
	std::cout << "month." << RESET << std::endl;

}

void	Harl::_error(void)
{
	std::cout << RED << BOLD << "ERROR" << RESET << std::endl;
    std::cout << BOLD << RED << "This is unacceptable ! I want to speak to the manager now.";
	std::cout << RESET << std::endl;
}