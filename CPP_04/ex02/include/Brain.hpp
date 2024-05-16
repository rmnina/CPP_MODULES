/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 03:29:40 by jdufour           #+#    #+#             */
/*   Updated: 2024/05/16 19:41:49 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

# define RED		"\x1b[31m"
# define BLUE		"\x1b[34m"
# define RESET		"\x1b[0m"
# define GREEN		"\x1b[32m"
# define PINK		"\x1b[95m"
# define YELLOW 	"\x1b[33m"
# define ORANGE 	"\x1b[38;5;208m"
# define PURPLE 	"\x1b[38;5;129m"
# define TURQUOISE	"\x1b[38;5;80m"
# define MAGENTA	"\x1b[35m"
# define BOLD		"\x1b[1m"
# define ITALIC		"\x1b[3m"

class Brain
{

protected:
	std::string	_ideas[100];

public:
	Brain( void);
	Brain( const Brain &src);

	void		set_idea( int *i, const std::string idea);
	std::string	get_idea( int *i) const;
	
	Brain	&operator=( const Brain &rhs);

	~Brain( void);
};

#endif