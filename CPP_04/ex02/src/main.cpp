/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:05:38 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/16 21:33:51 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

int main()
{
	AAnimal	*AnimalTab[10];

	std::cout << BOLD << "Instantiate Dog and Cat classes via pointers to Animal. ";
	std::cout << "Animal, Dog, Cat and Brain constructors should be called." << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			AnimalTab[i] = new Dog();
		else
		 	AnimalTab[i] = new Cat();
	}
	std::cout << std::endl;
	std::cout << BOLD << "Calling the 'make noise' functions." << RESET << std::endl;
	for (int i = 0; i < 10; i++)
		AnimalTab[i]->makeSound();
	std::cout << std::endl;
	std::cout << BOLD << "Deleting all of the objects. Animal, Dog, Cat and Brain destructors should be called." << RESET << std::endl;
	for (int i = 0; i < 10; i++)
		delete AnimalTab[i];
	std::cout << std::endl;

	std::cout << BOLD << "Uncomment the last lines in main to try to instanciate AAnimal alone." << std::endl;
	std::cout << "The compiler won't accept it." << RESET << std::endl;

	// AAnimal *animal = new AAnimal();
	// animal->makeSound();
	// delete animal;

	return (0);
}