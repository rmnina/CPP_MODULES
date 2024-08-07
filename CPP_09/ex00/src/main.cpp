/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:08:28 by jdufour           #+#    #+#             */
/*   Updated: 2024/08/07 19:42:48 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error : One argument needed." << std::endl;
		std::cerr << "Usage : ./btc [path_to_input_file]" << std::endl;
		return (1);
	}
	BitcoinExchange	btc(argv[1]);
	btc.parseData();
	btc.parseInput();
	return (0);
}