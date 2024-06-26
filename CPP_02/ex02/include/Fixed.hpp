/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:33:49 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/14 04:15:36 by jdufour          ###   ########.fr       */
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

    int             getRawBits( void) const;
    float           toFloat( void) const;
    int             toInt( void) const;
    static Fixed    min(Fixed &a, Fixed &b);
    static Fixed    min(Fixed const &a, Fixed const &b);
    static Fixed    max(Fixed &a, Fixed &b);
    static Fixed    max(Fixed const &a, Fixed const &b);

    Fixed & operator=( Fixed const &rhs);
    Fixed operator+( Fixed const &rhs);
    Fixed operator-( Fixed const &rhs);
    Fixed operator*( Fixed const &rhs);
    Fixed operator/( Fixed const &rhs);

    bool operator<( Fixed const &rhs)const;
    bool operator>( Fixed const &rhs)const;
    bool operator<=( Fixed const &rhs)const;
    bool operator>=( Fixed const &rhs)const;
    bool operator==( Fixed const &rhs)const;
    bool operator!=( Fixed const &rhs)const;

    Fixed & operator++( void);
    Fixed operator++( int);
    Fixed & operator--( void);
    Fixed operator--( int);
    
    ~Fixed();
};

std::ostream & operator<<(std::ostream &os, const Fixed &rhs);

#endif