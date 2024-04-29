/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 03:31:26 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/29 04:05:38 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

# define RED	"\x1b[31m"
# define BLUE	"\x1b[34m"
# define RESET	"\x1b[0m"
# define GREEN	"\x1b[32m"
# define PINK	"\x1b[95m"
# define YELLOW "\x1b[33m"
# define ORANGE "\x1b[38;5;208m"
# define BOLD	"\x1b[1m"
# define ITALIC	"\x1b[3m"

class Harl
{
public:
	void	complain(std::string level);

private:
	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);
};

#endif