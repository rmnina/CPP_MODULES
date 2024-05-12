/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 23:29:41 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/13 00:47:05 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

int main(void)
{
    ScavTrap x("Roger");
    ScavTrap y("Jane");
    
    x.attack("Jane");
    x.takeDamage(50);
    y.attack("Roger");
    y.takeDamage(10);

    ScavTrap z;
    z.beRepaired(10);
    z.takeDamage(120);
    z.beRepaired(20);

    x.attack("Creeper");
    x.takeDamage(90);
    x.attack("Creeper");
    y.get_gardGate();
    
	return (0);
}