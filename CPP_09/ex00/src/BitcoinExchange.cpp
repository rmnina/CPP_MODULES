/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:59:19 by jdufour           #+#    #+#             */
/*   Updated: 2025/03/08 17:14:17 by jdufour          ###   ########.fr       */
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
				_map[line.substr(0, 10)] = atof(line.c_str() + 11);
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
		input.open(_filename.c_str());
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
				BitcoinExchange::getErrFormatInput(line, i);
			if (i > 0)
			{
				std::string								date(line, 0, 10); 
				std::map<std::string, double>::iterator	it = _map.find(date);

				if (it == _map.end())
				{
					it = _map.lower_bound(date);
					if (it == _map.end())
						throw BitcoinExchange::ParsingErrorException("Date too recent to retrieve an accurate exchange rate -> " + line.substr(0, 10), i);
					else if (it == _map.begin())
						throw BitcoinExchange::ParsingErrorException("Date too old : data starts from 2009-01-02 -> " + line.substr(0, 10), i);
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

void	BitcoinExchange::getErrFormatInput( std::string line, int line_nb)
{
	if (line_nb > 0)
	{
		if (!line.empty() && line.size() < 14)
			throw BitcoinExchange::ParsingErrorException("Missing data on this line -> " + std::string(line), line_nb);
		if (line[4] != '-' || line[7] != '-' || line.compare(10, 3, " | "))
			throw BitcoinExchange::ParsingErrorException("Bad format. Try : YYYY-MM-DD | [quantity] -> " + std::string(line), line_nb);
		if (!is_int(line.substr(13, line.size() - 13).c_str()) && !is_double(line.substr(13, line.size() - 13).c_str()))
			throw BitcoinExchange::ParsingErrorException("Invalid number format -> " + line.substr(13, line.size() - 13), line_nb);
		if (atol(line.substr(13, line.size() - 13).c_str()) < 0 || atol(line.substr(13, line.size() - 13).c_str()) > 1000)
			throw BitcoinExchange::ParsingErrorException("Quantity should be between 0 and 1000 -> " + line.substr(13, line.size() - 13), line_nb);
		BitcoinExchange::getErrDate(line, line_nb);
	}
}

void	BitcoinExchange::getErrFormatDatabase( std::string line, int line_nb)
{
	if (line_nb > 0)
	{
		if (!line.empty() && line.size() < 12)
			throw BitcoinExchange::ParsingErrorException("Missing data on this line -> " + std::string(line), line_nb);
		if (line[4] != '-' || line[7] != '-' || line[10] != ',')
			throw BitcoinExchange::ParsingErrorException("Bad format. Try : YYYY-MM-DD,[exchange_rate] -> " + std::string(line), line_nb);
		if (!is_int(line.substr(11, line.size() - 11).c_str()) && !is_double(line.substr(11, line.size() - 11).c_str()))
			throw BitcoinExchange::ParsingErrorException("Invalid number format -> " + line.substr(11, line.size() - 11), line_nb);
		if (atol(line.substr(11, line.size() - 11).c_str()) < 0 || atol(line.substr(11, line.size() - 11).c_str()) > 66064)
			throw BitcoinExchange::ParsingErrorException("I don't think the bitcoin prices went this crazy... -> " + line.substr(11, line.size() - 11), line_nb);
		BitcoinExchange::getErrDate(line, line_nb);
	}
}

void	BitcoinExchange::getErrDate( std::string line, int line_nb)
{
		long int year = atol(line.substr(0, 4).c_str());
		if (year < 2009 || year > 2022)
			throw BitcoinExchange::ParsingErrorException("Invalid date : No data out of the 2009 - 2022 range -> " + line.substr(0, 10), line_nb);
		long int month = atol(line.substr(5, 2).c_str());
		if (month < 1 || month > 12)
			throw BitcoinExchange::ParsingErrorException("Invalid date : did you just invented a month?? -> " + line.substr(0, 10), line_nb);
		long int day = atol(line.substr(8, 2).c_str());
		if (day < 1 || day > 31)
			throw BitcoinExchange::ParsingErrorException("Invalid date : I'm not sure this date exists... -> " + line.substr(0, 10), line_nb);
		if ((year % 4 && month == 2 && day > 28) || (!(year % 4) && month == 2 && day > 29))
			throw BitcoinExchange::ParsingErrorException("Invalid date : you sure about this february thing ? -> " + line.substr(0, 10), line_nb);
		if ((month <= 7 && !(month % 2) && day > 30) || (month > 7 && month % 2 && day > 30))
			throw BitcoinExchange::ParsingErrorException("Invalid date : this month doesn't have a 31st... -> " + line.substr(0, 10), line_nb);
}

const char	*BitcoinExchange::ParsingErrorException::what( void) const throw()
{
	std::ostringstream	oss;
	oss << "Error : invalid format at line " << _line + 1 << " : \"" << _message << "\"";
	_error = oss.str();
	return (_error.c_str());
}

BitcoinExchange::~BitcoinExchange( void) {}