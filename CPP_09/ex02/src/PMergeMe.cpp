/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 01:46:12 by jdufour           #+#    #+#             */
/*   Updated: 2024/08/14 02:41:23 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PMergeMe.hpp"
#include "../../ex00/include/ScalarConverter.hpp"
#include "../../ex00/src/ScalarConverter.cpp"

PMergeMe::PMergeMe( void) {}

PMergeMe::PMergeMe( char **argv)
{
	for (int i = 0; argv[i]; i++)
	{
		if (is_int(argv[i]) && atol(argv[i]) >= 0)
		{
			_vector.push_back(atol(argv[i]));
			_deque.push_back(atol(argv[i]));
		}
		else
			throw std::runtime_error("Error : invalid arguments. Each argument should be a positive integer.");
	}
}

PMergeMe::PMergeMe( const PMergeMe &src)
{
	*this = src;
}

PMergeMe	&PMergeMe::operator=( const PMergeMe &rhs)
{
	this->_vector = rhs._vector;
	this->_deque = rhs._deque;
	return (*this);
}

std::deque<std::deque<int> >	PMergeMe::split( std::deque<int> &a)
{
	std::deque<std::deque<int> >	d_array;
	for (std::deque<int>::iterator it = a.begin(); it < a.end(); it += GP_SIZE)
	{
		std::deque<int>	temp;
		if (it + GP_SIZE < a.end())
			temp.assign(it, it + GP_SIZE);
		else
			temp.assign(it, a.end());
		d_array.push_back(temp);
	}
	return (d_array);
}

std::vector<std::vector<int> >	PMergeMe::split( std::vector<int> &a)
{
	std::vector<std::vector<int> >	v_array;
	for (std::vector<int>::iterator it = a.begin(); it < a.end(); it += GP_SIZE)
	{
		std::vector<int>	temp;
		if (it + GP_SIZE < a.end())
			temp.assign(it, it + GP_SIZE);
		else
			temp.assign(it, a.end());
		v_array.push_back(temp);
	}
	return (v_array);	
}

template <typename Container> void	PMergeMe::insert( Container &a)
{
	for (typename Container::iterator it = a.begin() + 1; it < a.end(); ++it)
	{
		int	value = *it;
		int	i = std::distance(a.begin(), it) - 1;
		while (i >= 0 && a[i] > value)
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = value;
	}
}

template <typename Container> Container	PMergeMe::merge( Container &a, Container &b)
{
	Container						temp;
	typename Container::iterator	it1 = a.begin();
	typename Container::iterator	it2 = b.begin();
	while (it1 < a.end() && it2 < b.end())
	{
		if (*it1 < *it2)
		{
			temp.push_back(*it1);
			it1++;
		}
		else
		{
			temp.push_back(*it2);
			it2++;
		}
	}
	while (it1 < a.end() || it2 < b.end())
	{
		if (it1 < a.end())
		{
			temp.push_back(*it1);
			it1++;
		}
		else
		{
			temp.push_back(*it2);
			it2++;
		}
	}
	return (temp);
}

template <typename Container> void	PMergeMe::insertStraggler( Container &a, int straggler)
{
	typename Container::iterator	it = a.begin();
	while (*it < straggler && it != a.end())
		it++;
	a.insert(it, straggler);
}

void	PMergeMe::mergeInsertVector( void)
{
	std::vector<std::vector<int> >	v_array;
	int								straggler = -1;

	std::cout << BOLD BLUE << "[std::vector] before : " << RESET BLUE << std::endl;
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << RESET << std::endl;
	if (_vector.size() % GP_SIZE == 1)
	{
		straggler = *(_vector.end() - 1);
		_vector.pop_back();
	}
    if (!_vector.empty())
    {
	    v_array = split(_vector);
	    for (std::vector<std::vector<int> >::iterator it = v_array.begin(); it < v_array.end(); ++it)
	    	PMergeMe::insert(*it);
	    while (v_array.size() > 1)
	    {
	    	for (std::vector<std::vector<int> >::iterator it = v_array.begin(); it + 1 < v_array.end(); ++it)
	    	{
	    		std::vector<int>	temp = PMergeMe::merge(*it++, *it);
	    		v_array.erase(it--);
	    		v_array.erase(it);
	    		v_array.push_back(temp);
	    	}
	    }
	    _vector = v_array[0];
    }
	if (straggler != -1)
		insertStraggler(_vector, straggler);
	std::cout << BOLD PINK << "[std::vector] after : " << RESET PINK << std::endl;
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << RESET << std::endl;
}

void	PMergeMe::mergeInsertDeque( void)
{
	std::deque<std::deque<int> >	d_array;
	int								straggler = -1;

	std::cout << BOLD BLUE << "[std::deque] before : " << RESET BLUE << std::endl;
	for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); ++it)
		std::cout << *it << " ";
	std::cout << RESET << std::endl;
	if (_deque.size() % GP_SIZE == 1)
	{
		straggler = *(_deque.end() - 1);	
		_deque.pop_back();
	}
    if (!_deque.empty())
    {
	    d_array = split(_deque);
	    for (std::deque<std::deque<int> >::iterator it = d_array.begin(); it < d_array.end(); ++it)
	    	PMergeMe::insert(*it);
	    while (d_array.size() > 1)
	    {
	    	std::deque<int>	temp = PMergeMe::merge(d_array[0], d_array[1]);
	    	d_array.pop_front();
	    	d_array.pop_front();
	    	d_array.push_back(temp);
	    }
	    _deque = d_array[0];
    }
	if (straggler != -1)
		insertStraggler(_deque, straggler);
	std::cout << BOLD PINK << "[std::deque] after : " << RESET PINK << std::endl;
	for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); ++it)
		std::cout << *it << " ";
	std::cout << RESET << std::endl;
}

void	PMergeMe::mergeInsert( void)
{
	clock_t		start_v, start_d, end_v, end_d;
	double		time_taken_v, time_taken_d;
	
	start_v = clock();
	mergeInsertVector();
	end_v = clock();
	start_d = clock();
	mergeInsertDeque();
	end_d = clock();
	time_taken_d = (static_cast<double>(end_d - start_d) / CLOCKS_PER_SEC) * 1000000;
	time_taken_v = (static_cast<double>(end_v - start_v) / CLOCKS_PER_SEC) * 1000000;
	std::cout << BOLD TURQUOISE << "Time to process a range of " << _vector.size() << " elements with std::vector : " << GREEN << time_taken_v << TURQUOISE << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << GREEN << time_taken_d << TURQUOISE << " us" << RESET << std::endl;
}

PMergeMe::~PMergeMe( void) {}