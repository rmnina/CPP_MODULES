/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:45:14 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/04 21:07:32 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP 
# define B_HPP

# include "Base.hpp"

class B : public Base
{
	private:
		std::string	_type;

	public:
		B( void);
		std::string	get_type( void);
		~B( void);
};

#endif