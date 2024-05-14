/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:05:38 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/14 03:46:10 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

int main()
{
	Animal	AnimalTab[10];

	for (int i = 0; i < 5; i++)
		AnimalTab[i] = new Dog();
	

	return (0);
}