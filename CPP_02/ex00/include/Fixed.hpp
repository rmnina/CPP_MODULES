/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:12:34 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/14 04:14:38 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class Fixed
{
private:
    int                 _value;
    static const int    _bits = 8;
    
public:
    Fixed( void);
    Fixed( const Fixed &src);

    int getRawBits( void) const;

    Fixed & operator=( Fixed const &rhs);
    ~Fixed();
};

#endif
