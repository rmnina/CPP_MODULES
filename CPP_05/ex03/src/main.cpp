/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:09:15 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/02 18:36:13 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/Bureaucrat.hpp"

int main(void)
{
	Intern	Paul;
	Bureaucrat	Patrick("Patrick", 66);
	Bureaucrat	Tiff("Tiff", 44);
	AForm	*form = Paul.makeForm("bl", "Dennis");

	if (!form)
		return (0);
	form->beSigned(Patrick);
	Tiff.executeForm(*form);
	delete form;
	return (0);
}