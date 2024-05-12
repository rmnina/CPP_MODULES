/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:51:29 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/13 00:25:51 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <iomanip>

# define RED	"\x1b[31m"
# define BLUE	"\x1b[34m"
# define RESET	"\x1b[0m"
# define GREEN	"\x1b[32m"
# define PINK	"\x1b[95m"
# define YELLOW "\x1b[33m"
# define ORANGE "\x1b[38;5;208m"
# define BOLD	"\x1b[1m"
# define ITALIC	"\x1b[3m"

class ClapTrap 
{

private:
	std::string	_name;
	int			_hit_points;
	int			_energy_points;
	int			_attack_damage;

public:
	ClapTrap( void);
	ClapTrap( const std::string name);
	ClapTrap( const ClapTrap &src);

	ClapTrap	&operator=(const ClapTrap &rhs);

	void	attack( const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	
	~ClapTrap( void);
};

#endif