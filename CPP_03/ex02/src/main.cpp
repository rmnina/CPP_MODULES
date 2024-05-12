/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 23:29:41 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/13 00:47:39 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

int main(void)
{
    FragTrap x("Roger");
    FragTrap y("Jane");
    
    x.attack("Jane");
    x.takeDamage(50);
    y.attack("Roger");
    y.takeDamage(10);

    FragTrap z;
    z.beRepaired(10);
    z.takeDamage(120);
    z.beRepaired(20);

    x.attack("Creeper");
    x.takeDamage(90);
    x.attack("Creeper");
    y.get_highFives();
    
	return (0);
}