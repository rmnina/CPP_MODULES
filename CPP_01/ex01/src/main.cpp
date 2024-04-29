/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:57:16 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/28 23:12:37 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main(void)
{
    Zombie  *zombies;
    int     N;

    N = 4;
    zombies = zombieHorde(N, "Gon");
    if (!zombies)
    {
        std::cerr << "Error alloc" << std::endl;
        return (1);
    }
    for (int i = 0; i < N; i++)
        zombies[i].announce();
    delete[] zombies;
}