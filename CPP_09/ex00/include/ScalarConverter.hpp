/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:30:24 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/04 17:08:33 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <limits>
# include <cmath>
# include <cfloat>

class ScalarConverter
{
	private:
		ScalarConverter( void);
		ScalarConverter( const ScalarConverter &src);
		ScalarConverter	&operator=( const ScalarConverter &rhs);
		~ScalarConverter( void);

	public:
		static int	convert( const char *value);
};

int	is_char(std::string value);
int	is_int(const char *arg);
int	is_float(const char *arg);
int	is_double(const char *arg);

void	convert_char(char c);
void	convert_int(int i);
void	convert_float(double f);
void	convert_float_dec(double f);
void	convert_double(double d);
void	convert_double_dec(double d);

#endif