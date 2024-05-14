/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:58:25 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/14 04:14:30 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class Fixed
{

private:
    int                 _value;
    static const int    _bits = 8;
    
public:
    Fixed( void);
    Fixed( const int src);
    Fixed( const float src);
    Fixed( const Fixed &src);

    int     getRawBits( void) const;
    float   toFloat( void) const;
    int     toInt( void) const;

    Fixed & operator=( Fixed const &rhs);
    ~Fixed();
};

std::ostream & operator<<(std::ostream &os, const Fixed &src);

#endif