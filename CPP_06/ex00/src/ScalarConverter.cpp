/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:49:44 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/04 17:09:56 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void) {}

ScalarConverter::ScalarConverter( const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter	&ScalarConverter::operator=( const ScalarConverter &rhs) 
{
	(void)rhs;
	return (*this);
}

int	ScalarConverter::convert( const char *value)
{
	std::string	str(value);
	
	if (is_int(value))
	{
		if (str.size() > 11 || atol(value) > 2147483647 || atol(value) < -2147483648)
			return (std::cerr << "error : int overflow" << std::endl, 1);
		else
			convert_int(atoi(value));
	}
	else if (is_char(str))
		convert_char(value[0]);
	else if ((is_float(value) == 1 || is_float(value) == 7) && atof(value) <= __FLT_MAX__ && atof(value) >= -__FLT_MAX__)
		convert_float(atof(value));
	else if (is_float(value) || !str.compare("inff") || !str.compare("-inff") || !str.compare("nanf"))
		convert_float_dec(atof(value));
	else if (is_double(value) == 1 && atof(value) <= __DBL_MAX__ && atof(value) >= -__DBL_MAX__)
		convert_double(atof(value));
	else if (is_double(value) || !str.compare("inf") || !str.compare("-inf") || !str.compare("nan"))
		convert_double_dec(atof(value));
	else
		return (std::cerr << "error : bad argument" << std::endl, 1);
	return (0);
}

void	convert_int(int i)
{
	if (i < 41 || i > 176)
		std::cout << "char : impossible" << std::endl;
	else
		std::cout << "char : '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int : " << i << std::endl;
	std::cout << "float : " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<double>(i) << ".0" << std::endl;
}

void	convert_char(char c)
{
	std::cout << "char : '" << c << "'" << std::endl;
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<double>(c) << ".0" << std::endl;
}

void	convert_float(double f)
{
	if (f < 41 || f > 176)
		std::cout << "char : impossible" << std::endl;
	else
		std::cout << "char : '" << static_cast<char>(f) << "'" << std::endl;
	if (f < -2147483648 || f > 2147483647)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(f) << std::endl;
	if (f > 0 && f < FLT_MIN)
		std::cout << "float : -inff" << std::endl;
	else
		std::cout << "float : " << static_cast<float>(f) << ".0f" << std::endl;
	if (f > 0 && f < DBL_MIN)
		std::cout << "double : -inf" << std::endl;
	else
		std::cout << "double : " << f << ".0" << std::endl;
}

void	convert_float_dec(double f)
{
	if (f < 41 || f > 176 || std::isnan(f))
		std::cout << "char : impossible" << std::endl;
	else
		std::cout << "char : '" << static_cast<char>(f) << "'" << std::endl;
	if (f < -2147483648 || f > 2147483647 || std::isnan(f))
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(f) << std::endl;
	if (f > 0 && f < FLT_MIN)
		std::cout << "float : -inff" << std::endl;
	else
		std::cout << "float : " << static_cast<float>(f) << "f" << std::endl;
	if (f > 0 && f < DBL_MIN)
		std::cout << "double : -inf" << std::endl;
	else
		std::cout << "double : " << f << std::endl;
}

void	convert_double(double d)
{
	if (d < 41 || d > 176 || std::isnan(d))
		std::cout << "char : impossible" << std::endl;
	else
		std::cout << "char : '" << static_cast<char>(d) << "'" << std::endl;
	if (d < -2147483648 || d > 2147483647 || std::isnan(d))
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(d) << std::endl;
	if (d > 0 && d < FLT_MIN)
		std::cout << "float : -inff" << std::endl;
	else
		std::cout << "float : " << static_cast<float>(d) << ".0f" << std::endl;
	if (d > 0 && d < DBL_MIN)
		std::cout << "double : -inf" << std::endl;
	else
		std::cout << "double : " << d << ".0" << std::endl;
}

void	convert_double_dec(double d)
{
	if (d < 41 || d > 176 || std::isnan(d))
		std::cout << "char : impossible" << std::endl;
	else
		std::cout << "char : '" << static_cast<char>(d) << "'" << std::endl;
	if (d < -2147483648 || d > 2147483647 || std::isnan(d))
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(d) << std::endl;
	if (d > 0 && d < FLT_MIN)
		std::cout << "float : -inff" << std::endl;
	else
		std::cout << "float : " << static_cast<float>(d) << "f" << std::endl;
	if (d > 0 && d < DBL_MIN)
		std::cout << "double : -inf" << std::endl;
	else
		std::cout << "double : " << d << std::endl;
}

int	is_char(std::string value)
{
	if (value.size() != 1)
		return (0);
	return (1);
}

int	is_int(const char *arg)
{
	for (int i = 0; arg[i]; i++)
	{
		if (i == 0 && arg[i] == '-')
			i++;
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
	}
	return (1);
}

int	is_float(const char *arg)
{
	int i = 0;
	int j = 0;
	int	dec = 1;
	
	for (i = 0; arg[i]; i++)
	{
		if (i == 0 && arg[i] == '-')
			i++;
		if (arg[i] < '0' || arg[i] > '9')
			break;
	}
	if (arg[i] == '.')
	{
		if (i == 7)
			dec = i;
		if (i > 7)
			dec++;
		i++;
		for (j = i; arg[j]; j++)
		{
			if (arg[j] < '0' || arg[j] > '9')
				break;
			else if (arg[j] != '0' && dec != 7)
				dec = 2;
		}
		if (arg[j] == 'f')
			return (dec);
	}
	return (0);
}

int	is_double(const char *arg)
{
	int i = 0;
	int dec = 1;
	
	for (i = 0; arg[i]; i++)
	{
		if (i == 0 && arg[i] == '-')
			i++;
		if (arg[i] < '0' || arg[i] > '9')
			break;
	}
	if (arg[i] == '.')
	{
		i++;
		for (int j = i; arg[j]; j++)
		{
			if (arg[j] < '0' || arg[j] > '9')
				return (0);
			else if (arg[j] != '0')
				dec++;
		}
		return (dec);
	}
	return (0);
}

ScalarConverter::~ScalarConverter( void) {}