/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:59:16 by jdufour           #+#    #+#             */
/*   Updated: 2024/08/07 20:46:53 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <string>
# include <fstream>
# include <exception>

class	BitcoinExchange
{
	private:
		std::map<std::string, double>	_map;
		std::string						_filename;

	public:
		BitcoinExchange( void);
		BitcoinExchange( std::string input);
		BitcoinExchange( const BitcoinExchange &src);
		BitcoinExchange	&operator=( const BitcoinExchange &rhs);
		
		void	parseData( void);
		void	parseInput( void);
		void	getErrDate( const char *line, int i);
		void	getErrFormatDatabase( const char *line, int i);
		void	getErrFormatInput( const char *line, int i);

		class	ParsingErrorException : public std::exception
		{
			private:
				std::string			_message;
				const int			_line;
				mutable std::string	_error;
			
			public :
				ParsingErrorException(const std::string& message, int line) throw() : _message(message), _line(line) {}
				virtual ~ParsingErrorException() throw() {}
				virtual const char	*what( void) const throw();
		};
		
		~BitcoinExchange( void);		
};

#endif