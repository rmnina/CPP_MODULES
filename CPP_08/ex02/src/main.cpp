/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 01:52:25 by jdufour           #+#    #+#             */
/*   Updated: 2024/07/19 02:31:51 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "mstack top : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack top : " << mstack.top() << std::endl;
	std::cout << "mstack size : " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	MutantStack<int, std::vector<int> > vstack;
	vstack.push(5);
	vstack.push(17);
	std::cout << "vstack top : " << vstack.top() << std::endl;
	vstack.pop();
	std::cout << "vstack top : " << vstack.top() << std::endl;
	std::cout << "vstack size : " << vstack.size() << std::endl;
	vstack.push(3);
	vstack.push(5);
	vstack.push(737);
	//[...]
	vstack.push(0);
	MutantStack<int, std::vector<int> >::iterator it2 = vstack.begin();
	MutantStack<int, std::vector<int> >::iterator ite2 = vstack.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::stack<int, std::vector<int> > v(vstack);
	
	return (0);
}