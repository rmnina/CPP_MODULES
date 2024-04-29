/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:13:26 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/28 23:03:48 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main(void)
{
    Zombie  *zombie1;
    Zombie  *zombie2;
    
    randomChump("Sébastien");
    randomChump("Jovica");
    zombie1 = new_Zombie("Président Marnais");
    if (!zombie1)
    {
        std::cerr << "Error alloc" << std::endl;
        return (1);
    }
    zombie1->announce();
    zombie2 = new_Zombie("Le Protecteur");
    if (!zombie2)
    {
        delete zombie1;
        std::cerr << "Error alloc" << std::endl;
        return (1);
    }
    zombie2->announce();
    delete zombie1;
    delete zombie2;
    return (0);
}