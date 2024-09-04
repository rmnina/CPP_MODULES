/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:47:09 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/04 19:34:59 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

int	main( void)
{
	Data		data;
	Data		*new_data;
	__intptr_t	ptr;

	data.i = 42;
	data.f = 1337.0f;
	data.c = 's';
	data.info = "Tranquille ici???";

	std::cout << data.i << std::endl;
	std::cout << data.f << std::endl;
	std::cout << data.c << std::endl;
	std::cout << data.info << std::endl;

	ptr = Serializer::serialize(&data);
	std::cout << ptr << std::endl;

	new_data = Serializer::deserialize(&ptr);
	std::cout << new_data->i << std::endl;
	std::cout << new_data->f << std::endl;
	std::cout << new_data->c << std::endl;
	std::cout << new_data->info << std::endl;
	
}

