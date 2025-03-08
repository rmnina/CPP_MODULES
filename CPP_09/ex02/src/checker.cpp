/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:54:32 by jdufour           #+#    #+#             */
/*   Updated: 2025/03/08 22:04:19 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <string>
#include <exception>

# define RED		"\x1b[31m"
# define RESET		"\x1b[0m"
# define GREEN		"\x1b[32m"
# define BLUE		"\x1b[34m"
# define BOLD		"\x1b[1m"
# define ITALIC		"\x1b[3m"

std::string		rmColor(std::string nb)
{
	std::string	clear;
	size_t		pos;

	pos = nb.find_last_of('m');
	if (pos == std::string::npos)
		return (nb);
	pos += 1;
	clear = nb.substr(pos, nb.size() - pos);
	return (clear);
}

std::vector<int>	parseVector(std::string output)
{
	size_t	vector_pos = output.find("[std::vector] after :") + 22;
	size_t	vector_end = output.find("[std::deque] before :");

	std::string	portion = output.substr(vector_pos, vector_end - vector_pos);

	std::vector<int>	vector;
	for (size_t i = 0; i < portion.size(); i++)
	{	
		std::string	nb;
		size_t		nb_pos = portion.find(" ", i);
		if (nb_pos == std::string::npos)
			break;
		while (i < nb_pos)
		{
			nb += portion[i];
			i++;
		}
		nb = rmColor(nb);
		vector.push_back(std::atol(nb.c_str()));
	}
	return (vector);
}

std::vector<int>	parseDeque(std::string output)
{
	size_t	deque_pos = output.find("[std::deque] after :") + 21;
	size_t	deque_end = output.find("Time to process");

	std::string	portion = output.substr(deque_pos, deque_end - deque_pos);

	std::vector<int> deque;

	for (size_t i = 0; i < portion.size(); i++)
	{
		std::string	nb;
		size_t		nb_pos = portion.find(" ", i);

		if (nb_pos == std::string::npos)
			break;

		while (i < nb_pos)
		{
			nb += portion[i];
			i++;
		}
		nb = rmColor(nb);
		deque.push_back(std::atol(nb.c_str()));
	}
	return (deque);
}

bool	checkSort(std::string output)
{
	std::vector<int>	vector, deque;
	int					tmp = 0;
	bool				oopsie = false;

	vector = parseVector(output);
	deque = parseDeque(output);

	for (std::vector<int>::iterator it = vector.begin(); it < vector.end(); ++it)
	{
		if (*it < tmp)
		{
			std::cout << RED BOLD << "ERROR : VECTOR IS NOT SORTED" << std::endl;
			oopsie = true;
			break;
		}
		tmp = *it;
	}
	if (!oopsie)
		std::cout << GREEN << "VECTOR : " << BOLD << "OK" << RESET << std::endl;
	
	tmp = 0;
	oopsie = false;
	
	for (std::vector<int>::iterator it = deque.begin(); it < deque.end(); ++it)
	{
		if (*it < tmp)
		{
			std::cout << RED BOLD << "ERROR : VECTOR IS NOT SORTED" << std::endl;
			oopsie = true;
			break;
		}
		tmp = *it;
	}
	if (!oopsie)
		std::cout << GREEN << "DEQUE : " << BOLD << "OK" << RESET << std::endl;
	return (oopsie);
}

int main()
{
	std::string line;
	std::string	error;
	std::string	output;

	while (std::getline(std::cin, line)) 
	{
		std::cout << line << std::endl;
		output += line;
	}
	if (output.empty())
		return (1);
	std::cout << BLUE BOLD ITALIC << "\nChecking if the values are, INDEED, sorted..." << RESET << std::endl;
	if (!checkSort(output))
		std::cout << BLUE BOLD ITALIC << "All good hehe 😎" << RESET << std::endl;
	else
		std::cout << BLUE BOLD ITALIC << "Oh nooooooo 😵" << RESET << std::endl;
	return (0);
}