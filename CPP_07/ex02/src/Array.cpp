/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:05:02 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/18 17:54:55 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"

template <typename T>
Array<T>::Array( void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_array = new T[0];
	this->_size = 0;
}

template <typename T>
Array<T>::Array( unsigned int n)
{
	std::cout << "Parametric constructor called" << std::endl;
	this->_array = new T[n];
	this->_size = n;
}

template <typename T>
Array<T>::Array( const Array<T> &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_array = new T[src._size];
	this->_size = src._size;
	for (int i = 0; i < this->_size; i++)
		this->_array[i] = src._array[i];
}

template <typename T>
Array<T>	&Array<T>::operator=( const Array<T> &rhs)
{
	if (this != &rhs)
	{
		delete[] this->_array;
		this->_array = new T[rhs._size];
		this->_size = rhs._size;
		for (int i = 0; i < this->_size; i++)
			this->_array[i] = rhs._array[i];
	}
	return (*this);
}

template <typename T>
const char	*Array<T>::OutOfRangeException::what( void) const throw()
{
	return ("Error : index out of range.");
}

template <typename T>
const int	&Array<T>::size( void) const
{
	return (this->_size);	
}

template <typename T>
T	&Array<T>::operator[]( const int index)
{
	if (index < 0 || index >= _size || _size == 0)
		throw (Array<T>::OutOfRangeException());
	return (this->_array[index]);
}

template <typename T>
Array<T>::~Array( void)
{
	std::cout << "Destructor called" << std::endl;
	delete[] this->_array;
}