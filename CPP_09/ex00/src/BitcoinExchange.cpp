/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:59:19 by jdufour           #+#    #+#             */
/*   Updated: 2024/08/07 21:30:38 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"
#include "../include/ScalarConverter.hpp"

BitcoinExchange::BitcoinExchange( void) {}

BitcoinExchange::BitcoinExchange( std::string input)
{
	_filename = input;
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange	&BitcoinExchange::operator=( const BitcoinExchange &rhs)
{
	this->_filename = rhs._filename;
	this->_map = rhs._map;
	return (*this);
}

void	BitcoinExchange::parseData( void)
{
	std::string		line;
	std::ifstream	db;
	int				i = 0;

	try
	{
		db.open("data.csv");
	}
	catch (const std::ifstream::failure &e)
	{
		std::cerr << e.what() << std::endl;
	}
	for (i = 0; std::getline(db, line); i++)
	{
		try
		{
			BitcoinExchange::getErrFormatDatabase(line.c_str(), i);
			if (i > 0)
				_map[strndup(line.c_str(), 10)] = atof(line.c_str() + 11);
		}
		catch (const BitcoinExchange::ParsingErrorException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

void	BitcoinExchange::parseInput( void)
{
	std::string		line;
	std::ifstream	input;
	int				i = 0;

	try
	{
		input.open(_filename);
	}
	catch (const std::ifstream::failure &e)
	{
		std::cerr << e.what() << std::endl;
	}
	for (i = 0; std::getline(input, line); i++)
	{
		try
		{
			if (!line.empty())
				BitcoinExchange::getErrFormatInput(line.c_str(), i);
			if (i > 0)
			{
				std::string								date(line, 0, 10); 
				std::map<std::string, double>::iterator	it = _map.find(date);

				if (it == _map.end())
				{
					it = _map.lower_bound(date);
					if (it == _map.end())
						throw BitcoinExchange::ParsingErrorException("Date too recent to retrieve an accurate exchange rate -> " + std::string(line, 0, 10), i);
					else if (it == _map.begin())
						throw BitcoinExchange::ParsingErrorException("Date too old : data starts from 2009-01-02 -> " + std::string(line, 0, 10), i);
					else
						--it;
				}
				std::cout << date << " => " << line.c_str() + 13 << " = " << it->second * atof(line.c_str() + 13) << std::endl;
			}
		}
		catch (const BitcoinExchange::ParsingErrorException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

void	BitcoinExchange::getErrFormatInput( const char *line, int line_nb)
{
	if (line_nb > 0)
	{
		if (line && strlen(line) < 14)
			throw BitcoinExchange::ParsingErrorException("Missing data on this line -> " + std::string(line), line_nb);
		if (line[4] != '-' || line[7] != '-' || strncmp(line + 10, " | ", 3))
			throw BitcoinExchange::ParsingErrorException("Bad format. Try : YYYY-MM-DD | [quantity] -> " + std::string(line), line_nb);
		if (!is_int(line + 13) && !is_double(line + 13))
			throw BitcoinExchange::ParsingErrorException("Invalid number format -> " + std::string(line + 13), line_nb);
		if (atol(line + 13) < 0 || atol(line + 13) > 1000)
			throw BitcoinExchange::ParsingErrorException("Quantity should be between 0 and 1000 -> " + std::string(line + 13), line_nb);
		BitcoinExchange::getErrDate(line, line_nb);
	}
}

void	BitcoinExchange::getErrFormatDatabase( const char *line, int line_nb)
{
	if (line_nb > 0)
	{
		if (line && strlen(line) < 12)
			throw BitcoinExchange::ParsingErrorException("Missing data on this line -> " + std::string(line), line_nb);
		if (line[4] != '-' || line[7] != '-' || line[10] != ',')
			throw BitcoinExchange::ParsingErrorException("Bad format. Try : YYYY-MM-DD,[exchange_rate] -> " + std::string(line), line_nb);
		if (!is_int(line + 11) && !is_double(line + 11))
			throw BitcoinExchange::ParsingErrorException("Invalid number format -> " + std::string(line + 11), line_nb);
		if (atol(line + 11) < 0 || atol(line + 11) > 66064)
			throw BitcoinExchange::ParsingErrorException("I don't think the bitcoin prices went this crazy... -> " + std::string(line + 11), line_nb);
		BitcoinExchange::getErrDate(line, line_nb);
	}
}

void	BitcoinExchange::getErrDate( const char *line, int line_nb)
{
		long int year = atol(strndup(line, 4));
		if (year < 2009 || year > 2022)
			throw BitcoinExchange::ParsingErrorException("Invalid date : No data out of the 2009 - 2022 range -> " + std::string(strndup(line, 10)), line_nb);
		long int month = atol(strndup(line + 5, 2));
		if (month < 1 || month > 12)
			throw BitcoinExchange::ParsingErrorException("Invalid date : did you just invented a month?? -> " + std::string(strndup(line, 10)), line_nb);
		long int day = atol(strndup(line + 8, 2));
		if (day < 1 || day > 31)
			throw BitcoinExchange::ParsingErrorException("Invalid date : I'm not sure this date exists... -> " + std::string(strndup(line, 10)), line_nb);
		if ((year % 4 && month == 2 && day > 28) || (!(year % 4) && month == 2 && day > 29))
			throw BitcoinExchange::ParsingErrorException("Invalid date : you sure about this february thing ? -> " + std::string(strndup(line, 10)), line_nb);
		if ((month <= 7 && !(month % 2) && day > 30) || (month > 7 && month % 2 && day > 30))
			throw BitcoinExchange::ParsingErrorException("Invalid date : this month doesn't have a 31st... -> " + std::string(strndup(line, 10)), line_nb);
}

const char	*BitcoinExchange::ParsingErrorException::what( void) const throw()
{
	std::ostringstream	oss;
	oss << "Error : invalid format at line " << _line + 1 << " : \"" << _message << "\"";
	_error = oss.str();
	return (_error.c_str());
}

BitcoinExchange::~BitcoinExchange( void) {}