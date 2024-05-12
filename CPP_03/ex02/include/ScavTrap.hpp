/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 23:58:44 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/13 00:46:33 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

private:
	void	gardGate();

public:
	ScavTrap( void);
	ScavTrap( std::string name);
	ScavTrap( ScavTrap &src);
	void	get_gardGate();
	void    attack( const std::string &target);

	ScavTrap	&operator=(const ScavTrap &rhs);

	~ScavTrap( void);
	
};

#endif