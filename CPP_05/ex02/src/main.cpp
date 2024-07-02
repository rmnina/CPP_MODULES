/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:09:15 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/01 23:28:10 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main(void)
{
	// Bureaucrat	sylvie("Sylvie", 150);
	Bureaucrat	herve("Herve", 25);
	Bureaucrat	bigboss("BigBoss", 1);

	RobotomyRequestForm form1("daniel");
	herve.signForm(form1);
	form1.execute(bigboss);
	
	return (0);
}