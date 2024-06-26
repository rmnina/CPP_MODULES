/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:09:15 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/30 17:45:16 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main(void)
{
	Bureaucrat sylvie("Sylvie", 150);

	sylvie.demote();
	std::cout << sylvie << std::endl;
	sylvie.promote();
	std::cout << sylvie << std::endl;
	return (0);
}