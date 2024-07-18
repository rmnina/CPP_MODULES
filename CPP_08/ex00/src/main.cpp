/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:42:16 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/18 20:30:49 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"
#include <list>
#include <vector>
#include <deque>

int main(void)
{
	std::vector<int> a;
	for (int i = 1; i < 6; i++)
		a.push_back(i);
	std::deque<int> b;
	for (int i = 6; i < 11; i++)
		b.push_back(i);
	std::list<int> c;
	for (int i = 1; i < 6; i++)
		c.push_back(i);
	try
	{
		easyfind(a, 5);
		std::cout << "Value " << 5 << " found at index " << *easyfind(a, 5) - *a.begin() << std::endl;
	}
	catch(const std::logic_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		easyfind(b, 8);
		std::cout << "Value " << 8 << " found at index " << *easyfind(b, 8) - *b.begin() << std::endl;
	}
	catch(const std::logic_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		easyfind(c, 8);
		std::cout << "Value " << 8 << " found at index " << *easyfind(c, 8) - *c.begin() << std::endl;
	}
	catch(const std::logic_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
