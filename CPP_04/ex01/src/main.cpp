/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:05:38 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/26 14:45:55 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

int main()
{
	Animal	*AnimalTab[10];
	int		i = 0;

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

	
	std::cout << BOLD << "Instantiate Dogs and Cat directly on stack" << RESET << std::endl; 
	Dog	dog;
	Cat	cat;

	std::cout << std::endl;
	std::cout << BLUE << "Dog first idea : " << dog.get_idea( &i) << RESET << std::endl;
	std::cout << "Modifing dog first idea..." << std::endl;
	dog.set_idea( &i, "I am a dog !!");
	std::cout << BLUE << "Dog new first idea : " << dog.get_idea( &i) << RESET << std::endl;
	i = 99;
	std::cout << BLUE << "Dog last idea : " << dog.get_idea( &i) << std::endl << RESET << std::endl;

	i = 0;
	std::cout << ORANGE << "Cat first idea : " << cat.get_idea( &i) << RESET << std::endl;
	std::cout << "Modifing cat first idea..." << std::endl;
	cat.set_idea( &i, "I am a cat !!");
	std::cout << ORANGE << "Cat new first idea : " << cat.get_idea( &i) << RESET << std::endl;
	i = 99;
	std::cout << ORANGE << "Cat last idea : " << cat.get_idea( &i) << RESET << std::endl << std::endl;
	// delete[] AnimalTab;
	return (0);
}