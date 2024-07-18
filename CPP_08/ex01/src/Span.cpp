/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:59:25 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/19 00:07:20 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

Span::Span( void)
{
	_array = new unsigned int[0];
	_size = 0;
	_capacity = 0;
}

Span::Span( const unsigned int N)
{
	_array = new unsigned int[N];
	_size = N;
	_capacity = 0;
}

Span::Span( const Span &src)
{
	_array = new unsigned int[src._size];
	_size = src._size;
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
	_capacity = src._capacity;
}

Span	&Span::operator=( const Span &rhs)
{
	if (this != &rhs)
	{
		delete[] _array;
		_array = new unsigned int[rhs._size];
		_size = rhs._size;
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = rhs._array[i];
		_capacity = rhs._capacity;
	}
	return (*this);
}

void	Span::addNumber( const unsigned int value)
{
	if (_size == 0)
		throw(std::logic_error("Error: size is NULL."));
	if (_capacity == _size)
		throw(std::logic_error("Error: Value couldn't be add : Container is full."));
	_array[_capacity] = value;
	_capacity++;
}

unsigned int	Span::getNumber( int index) const
{
	return (_array[index]);
}

void	Span::insert( const unsigned int *src, const unsigned int size)
{	
	if (_size == 0)
		throw(std::logic_error("Error: size is NULL."));
	if (size > _size - _capacity)
		throw(std::logic_error("Error: destination size insufficient"));
	for (unsigned int i = _capacity; i < size; i++)
		_array[i] = src[i];
	_capacity += size;
}

unsigned int	Span::shortestSpan( void) const
{
	int shortestSpan;
	
	if (_size < 2)
		throw(std::logic_error("Error: Too few numbers stored."));
	shortestSpan = std::abs(static_cast<int>(_array[1]) - static_cast<int>(_array[0]));
	std::sort(_array, _array + _capacity);
	for (unsigned int i = 1; i < _capacity; i++)
	{
		if (std::abs(static_cast<int>(_array[i - 1]) - static_cast<int>(_array[i])) < shortestSpan)
			shortestSpan = std::abs(static_cast<int>(_array[i - 1]) - static_cast<int>(_array[i]));
	}
	return (shortestSpan);
}

unsigned int	Span::longestSpan( void) const
{
	unsigned int	min;
	unsigned int	max = 0;

	if (_size < 2)
		throw(std::logic_error("Error: Too few numbers stored."));
	min = _array[0];
	for (unsigned int i = 0; i < _capacity; i++)
	{
		if (_array[i] > max)
			max = _array[i];
		if (_array[i] < min)
			min = _array[i];
	}
	return (max - min);
}

Span::~Span( void)
{
	delete[] _array;
}