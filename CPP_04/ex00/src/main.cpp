/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:05:38 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/26 14:38:20 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"

int main()
{
	std::cout << BOLD << "Here we can see all the constructors." << RESET << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl << BOLD << "We check the type of derived classes that we have instantiated via a pointer to the parent class." << RESET << std::endl;
	
	std::cout << BLUE << j->getType() << " " << RESET << std::endl;
	std::cout << ORANGE << i->getType() << " " << RESET << std::endl;
	
	std::cout << std::endl << BOLD << "We call makeSound(). Each animal will make its own sound." << RESET << std::endl;
	
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl << BOLD << "We destroy our objects to avoid memory leaks." << RESET << std::endl;
	
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl << BOLD << "We create new objects. This time, they are poorly written and will not have the expected behaviour." << RESET << std::endl;

	const WrongAnimal	*wrong_meta = new WrongAnimal();
	const WrongAnimal	*wrong_i = new WrongCat();
	
	std::cout << std::endl << BOLD << "We check if our WrongCat's type is rightly initialized." << RESET << std::endl;

	std::cout << RED << wrong_i->getType() << " " << RESET << std::endl;
	
	std::cout << std::endl << BOLD << "We call makeSound(). This time, the WrongCat is not gonna make its right noise..." << RESET << std::endl;

	wrong_i->makeSound(); //will output the cat sound!
	wrong_meta->makeSound();

	std::cout << std::endl << BOLD << "We're done with this weird zoo..." << RESET << std::endl;

	delete wrong_i;
	delete wrong_meta;
	return (0);
}