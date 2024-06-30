/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:09:15 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/30 19:33:44 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main(void)
{
	Bureaucrat	sylvie("Sylvie", 150);
	Bureaucrat	herve("Herve", 25);
	Bureaucrat	bigboss("BigBoss", 1);

	Form	form0;
	Form	form1("form1", 30, 30);
	Form	form2("form2", 10, 10);

	sylvie.demote();
	std::cout << sylvie << std::endl;
	sylvie.promote();
	std::cout << sylvie << std::endl;
	
	std::cout << form1 << std::endl;
	
	form1.beSigned( &sylvie);
	form0.beSigned( &sylvie);
	std::cout << form0 << std::endl;
	herve.signForm(&form1);
	herve.signForm(&form2);
	form2.beSigned(&herve);
	std::cout << form2 << std::endl;
	form2.beSigned(&bigboss);
	std::cout << form2 << std::endl;
	
	return (0);
}