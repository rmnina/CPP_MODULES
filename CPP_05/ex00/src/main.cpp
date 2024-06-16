/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:09:15 by jdufour           #+#    #+#             */
/*   Updated: 2024/06/16 20:28:58 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main(void)
{
	Bureaucrat sylvie("Sylvie", 1);

	sylvie.promote();
	std::cout << sylvie << std::endl;
	sylvie.demote();
	return (0);
}