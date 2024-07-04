/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:48:22 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/04 21:11:38 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

Base	*generate(void)
{
	std::time_t	time = std::time(NULL);
	std::tm		*localtime = std::localtime(&time);
	int			rand = localtime->tm_sec % 3;

	if (rand == 0)
		return (std::cout << "A was randomly chosen..." << std::endl, new A());
	else if (rand == 1)
		return (std::cout << "B was randomly chosen..." << std::endl, new B());
	else
		return (std::cout << "C was randomly chosen..." << std::endl, new C());
}

void	identify(Base *p)
{
	Base	*res;

	res = dynamic_cast<A*>(p);
	if (res)
		std::cout << "It's A!" << std::endl;
	res = dynamic_cast<B*>(p);
	if (res)
		std::cout << "It's B!" << std::endl;
	res = dynamic_cast<C*>(p);
	if (res)
		std::cout << "It's C!" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		Base &res = dynamic_cast<A&>(p);
		(void)res;
		std::cout << "It's A again!" << std::endl;
	}
	catch (const std::bad_cast &e)
	{
		std::cout << "It's not A : " << e.what() << std::endl;
	}
	try
	{
		Base &res = dynamic_cast<B&>(p);
		(void)res;
		std::cout << "It's B again!" << std::endl;
	}
	catch (const std::bad_cast &e)
	{
		std::cout << "It's not B : " << e.what() << std::endl;
	}
	try
	{
		Base &res = dynamic_cast<C&>(p);
		(void)res;
		std::cout << "It's C again!" << std::endl;
	}
	catch (const std::bad_cast &e)
	{
		std::cout << "It's not C : " << e.what() << std::endl;
	}
}

Base::~Base( void) {}