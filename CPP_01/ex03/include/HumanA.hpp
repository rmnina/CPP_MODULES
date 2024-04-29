/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:36:36 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/29 00:22:47 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

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

class HumanA
{
	
public:

	HumanA(std::string name, Weapon &weapon);
	void	setWeapon(Weapon weapon);
	void    attack();

private:

	std::string	_name;
	Weapon		 &_weapon;
};

#endif