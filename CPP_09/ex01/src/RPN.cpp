/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:45:25 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/25 00:51:53 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

RPN::RPN( void) {}

RPN::RPN( const RPN &src)
{
	*this = src;
}

RPN	&RPN::operator=( const RPN &rhs)
{
	_stack = rhs._stack;
	return (*this);
}

bool	isOperand(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

void	RPN::parse( std::string str)
{
	std::string	res = str;
	int			nbs = 0;
	int			operands = 0;

	for (unsigned long int i = 0; i < res.size(); i++)
	{
		if (isdigit(res[i]))
			nbs++;
		else if (isOperand(res[i]))
			operands++;
		else if (res[i] == ' ')
		{
			res.erase(res.begin() + i);
			i--;
		}
		else
			throw(std::runtime_error("Error : invalid characters."));
	}
	if (nbs != operands + 1)
		throw(std::runtime_error("Error : there should be n - 1 operands."));
	for (int i = 0; res[i]; i++)
	{
		if (isdigit(res[i]))
			_stack.push(res[i] - 48);
		else
			RPN::compute(res[i]);
	}
}

void	RPN::add( void)
{
	int	result = _stack.top();
	_stack.pop();
	result += _stack.top();
	_stack.pop();
	_stack.push(result);
}

void	RPN::substract( void)
{
	int	result = _stack.top();
	_stack.pop();
	result = _stack.top() - result;
	_stack.pop();
	_stack.push(result);	
}

void	RPN::multiply( void)
{
	int result = _stack.top();
	_stack.pop();
	result *= _stack.top();
	_stack.pop();
	_stack.push(result);
}

void	RPN::divide( void)
{
	int	result = _stack.top();
	if (result == 0)
		throw (std::runtime_error("Error : div by 0"));
	_stack.pop();
	result = _stack.top() / result;
	_stack.pop();
	_stack.push(result);		
}


void	RPN::compute( const char c)
{
	if (c == '/')
		RPN::divide();
	else if (c == '*')
		RPN::multiply();
	else if (c == '-')
		RPN::substract();
	else if (c == '+')
		RPN::add();	
}

void	RPN::printVal( void)
{
	for (int i = 0; !_stack.empty(); i++)
	{
		std::cout << _stack.top() << std::endl;
		_stack.pop();
	}
}

RPN::~RPN( void) {}