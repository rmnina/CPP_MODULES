/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:56:09 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/28 23:12:09 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombieHorde;

	zombieHorde = new Zombie[N];
    if (!zombieHorde)
        return (NULL);
    for (int i = 0; i < N; i++)
	    zombieHorde[i].set_name(name);
	return (zombieHorde);
}