/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:12:06 by jdufour           #+#    #+#             */
/*   Updated: 2025/03/08 19:43:40 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <ctime>
# include <algorithm>

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

# define GP_SIZE	2

class PMergeMe
{
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		
	public:

/************************ COPLIEN ************************/
		PMergeMe( void);
		PMergeMe( char **argv);
		PMergeMe( const PMergeMe &src);
		PMergeMe	&operator=( const PMergeMe &rhs);
		~PMergeMe( void);

/************************ TEMPLATES ************************/
		template <typename Container>
		void		insert( Container &a);
		
		template <typename Container>
		Container	merge( Container &a, Container &b);
		
		template <typename Container>
		void		insertStraggler( Container &a, int straggler);

		template <typename Container>
		void		mergeInsert( Container &a);
		
/************************ OVERLOAD ************************/
		std::vector<std::vector<int> >	split( std::vector<int> &a);
		std::deque<std::deque<int> >	split( std::deque<int> &a);

/************************ ALGO ************************/
		
		std::vector<int>	jacobsthal_seq(int n);
		void				mergeInsertVector( void);
		void				mergeInsertDeque( void);
		void				mergeInsert( void);
		
};


#endif