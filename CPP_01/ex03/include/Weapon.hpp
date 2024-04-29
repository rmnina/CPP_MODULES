/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:36:25 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/29 00:28:20 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <iomanip>
# include <string>

# define RED	"\x1b[31m"
# define BLUE	"\x1b[34m"
# define RESET	"\x1b[0m"
# define GREEN	"\x1b[32m"
# define PINK	"\x1b[95m"
# define BOLD	"\x1b[1m"

class Weapon
{
	
public:

	Weapon(std::string type);
	const std::string	&getType(void) const;
	void				setType(std::string new_type);

private:

	std::string	_type;
};

#endif