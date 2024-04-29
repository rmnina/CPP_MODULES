/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:13:59 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/28 23:58:10 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define RED	"\x1b[31m"
#define RESET	"\x1b[0m"
#define GREEN	"\x1b[32m"
#define PINK    "\x1b[95m"
#define BOLD	"\x1b[1m"

/* A pointer is a variable that contains the memory address of another object.
A reference is an alias (another name) for an existing variable.

A pointer can be reassigned to point to another memory address, and it can be 
dereferenced (using the * operator) to access the target value.
A reference, once linked to a variable, cannot be reassigned to reference 
another variable. It acts as a constant alias for the initial variable

A pointer can be null, meaning it points to no memory address.
A reference must always be linked to an existing object and cannot be null.

Pointers can be used to perform arithmetic operations, such as incrementing 
or decrementing, to navigate through an array or data structure.
References do not support arithmetic operations, as they simply act as 
aliases to an existing variable.
*/

int main(void)
{
    std::string string = "HI THIS IS BRAIN";;
    std::string *stringPTR = &string;
    std::string &stringREF = string;
    
    std::cout << "Address of " << BOLD << "string : ";
    std::cout << GREEN << &string << std::endl << RESET;

    std::cout << "Address contained by " << BOLD << "stringPTR : ";
    std::cout << GREEN << stringPTR << std::endl << RESET;

    std::cout << "Address contained by " << BOLD << "stringREF : ";
    std::cout << GREEN << &stringREF << std::endl << RESET;
    
    std::cout << BOLD << "String " << RESET << "value : ";
    std::cout << BOLD << PINK << string << std::endl << RESET;

    std::cout << "Value pointed by " << BOLD << "stringPTR : ";
    std::cout << PINK << *stringPTR << std::endl << RESET;
    
    std::cout << "Value pointed by " << BOLD << "stringREF : ";
    std::cout << PINK << stringREF << std::endl << RESET;
}