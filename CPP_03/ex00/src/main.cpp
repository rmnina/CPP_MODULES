/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 23:29:41 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/12 23:57:09 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main(void)
{
	ClapTrap a("Alice");
	ClapTrap b("Bob");

    a.attack("Bob");
    a.takeDamage(5);
    b.attack("Alice");
    b.takeDamage(1);

    ClapTrap c;
    c.beRepaired(1);
    c.takeDamage(12);
    c.beRepaired(2);
    
    a.attack("Creeper");
    for (int i = 0; i < 10; i++)
        b.attack("Creeper");
    b.beRepaired(2);
    b.takeDamage(156);
    b.attack("Creeper");
    
	return (0);
}