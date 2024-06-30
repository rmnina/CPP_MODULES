/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:03:00 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/30 02:23:19 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/MateriaSource.hpp"

int	main( void)
{
	{
		std::cout << BOLD << "Tests from the subject : " << RESET << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << std::endl << BOLD << "Supplementary tests : " << RESET << std::endl << std::endl;

		Character	*Creeper = new Character("Creeper");
		Character	*copy = new Character(*Creeper);

		std::cout << BOLD PINK << "Verifying deep copy : " << RESET << std::endl;

		std::cout << ITALIC PINK << "Creepers name is " << Creeper->getName() << std::endl;
		std::cout << "Copys name is " << copy->getName() << RESET << std::endl;

		Creeper->setName("Steve");
		
		std::cout << ITALIC PINK << "Creepers newname is " << Creeper->getName() << std::endl;
		std::cout << "Copys name is " << copy->getName() << RESET << std::endl;
	
		std::cout << std::endl << BLUE BOLD << "Verifying that the materias are saved in the right order :" << std::endl << RESET ITALIC BLUE;
		AMateria	*ice = new Ice();
		AMateria	*cure = new Cure();
		Creeper->equip(ice);
		Creeper->equip(ice);
		Creeper->equip(ice);
		Creeper->equip(cure);

		Creeper->use(0, *copy);
		Creeper->use(1, *copy);
		Creeper->use(2, *copy);
		Creeper->use(3, *copy);

		std::cout << std::endl << BOLD GREEN << "Testing the unequip function" << RESET ITALIC GREEN << std::endl;
		Creeper->unequip(0);
		//Verifying if the index is empty. If so, it shouldnt print
		Creeper->use(0, *copy);
		//Verifying if the materia is not deleted
		Creeper->use(1, *copy);

		Creeper->unequip(1);
		delete copy;
		delete Creeper;
	}
	
	return (0);
}