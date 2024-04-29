/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:44:01 by jdufour           #+#    #+#             */
/*   Updated: 2024/04/29 04:13:11 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <cstring>
#include <iostream>

int	create_infile(std::string filename, std::ifstream *file)
{
	const char 		*cstr;

	cstr = filename.c_str();
	file->open(cstr);
	if (!file->is_open())
	{
		std::cerr << "Error : file '" << filename << "' could not be opened" << std::endl;
		return (1);
	}
	return (0);
}

int	create_outfile(std::string filename, std::ofstream *new_file)
{
	std::string		new_filename;
	const char 		*new_cstr;

	new_filename = filename;
	new_filename.append(".replace");
	new_cstr = new_filename.c_str();
	new_file->open(new_cstr);
	if (!new_file->is_open())
	{
		std::cerr << "Error : file '" << new_filename << "' could not be opened" << std::endl;
		return (1);
	}
	return (0);
}

void    ft_sed(std::ifstream *infile, std::ofstream *outfile, std::string s1, std::string s2)
{
	std::string		line;
	std::string		new_line;
	std::size_t		pos;
	std::size_t		old_pos;

	while (std::getline(*infile, line))
	{
		old_pos = 0;
		pos = line.find(s1, old_pos);
		while (pos != std::string::npos)
		{
			new_line += line.substr(old_pos, pos - old_pos);
			new_line += s2;
			old_pos = pos + s1.length();
			pos = line.find(s1, old_pos);
		}
		new_line += line.substr(old_pos);
		*outfile << new_line << std::endl;
		new_line.erase();
	}
}

int main(int argc, char **argv)
{
	std::string		s1;
	std::string		s2;
	std::ifstream	file;
	std::ofstream	outfile;
	
	if (argc != 4)
	{
		std::cerr << "Wrong number of arguments." << std::endl;
		std::cerr << "Usage : ./sed [filename] [string_to_replace] [new_string]" << std::endl;
		return (1);
	}
	s1 = argv[2];
	s2 = argv[3];
	if (create_infile((std::string)argv[1], &file))
		return (1);
	if (create_outfile((std::string)argv[1], &outfile))
	{
		file.close();
		return (1);
	}
	ft_sed(&file, &outfile, s1, s2);
	file.close();
	outfile.close();
	return (0);
}