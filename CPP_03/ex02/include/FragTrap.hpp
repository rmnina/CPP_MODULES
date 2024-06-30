/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:37:07 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/13 00:44:53 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "../include/ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	
private:
	void	highFivesGuys( void);

public:
	FragTrap( void);
	FragTrap( std::string name);
	FragTrap( FragTrap const &src);

	FragTrap	&operator=( const FragTrap &rhs);
	void	get_highFives( void);
	void    attack( const std::string &target);

	~FragTrap( void);

};

#endif