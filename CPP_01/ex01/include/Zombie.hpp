/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:57:07 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/28 23:10:27 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>
# include <string>

# define RED	"\x1b[31m"
# define RESET	"\x1b[0m"
# define GREEN	"\x1b[32m"
# define BOLD	"\x1b[1m"

class Zombie
{
	
public:

	void			set_name(std::string name);
	void			announce(void);
	~Zombie(void);

private:
	
	std::string	_name;
};

Zombie	*zombieHorde(int n, std::string name);

#endif