/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:36:46 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/17 12:53:16 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "../include/Weapon.hpp"

# define RED	"\x1b[31m"
# define BLUE	"\x1b[34m"
# define RESET	"\x1b[0m"
# define GREEN	"\x1b[32m"
# define PINK	"\x1b[95m"
# define BOLD	"\x1b[1m"

class HumanB
{
	
public:

	HumanB(std::string name);
	void	setWeapon(Weapon &weapon);
	void	attack();

private:

	std::string	_name;
	Weapon		*_weapon;
};

#endif