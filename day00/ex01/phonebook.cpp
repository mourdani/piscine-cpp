/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:48:09 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/01 20:53:46 by mourdani         ###   ########.fr       */
/*   Updated: 2022/08/28 20:54:02 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <unistd.h>
#include "phonebook.hpp"

bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

std::string	ptrunk(std::string str)
{
	int space_size;

	if (str.length() >= 10 )	return (str.substr(0,9) + ".");
	else if (str.length() < 10)
	{
		space_size = 10 - str.length();
		return (str.insert(0, "                    ", space_size));
	}
	return str;
}

int	check_empty(std::string str, int mode)
{
	if (mode == 1)
	{
		if ((str.find_first_not_of("abcdefhijklmnopqrstuvwxyz") != std::string::npos
			&& str.find_first_not_of(" \t") == std::string::npos) || str.empty())
		{
			std::cout << "Input only accepts alphabets" << std::endl;
			return 1;
		}
	}
	else if (mode == 2 && (str.find_first_not_of("01123456789") != std::string::npos || str.empty()))
	{
		std::cout << "Number must only contain digits" << std::endl;
		return 1;
	}
	return 0;
}

void	add_info(std::string str, int set)
{
	while (getline(std::cin, str))
		if (str != "")
		       	break;
	if (!check_empty(str, 1))
		set = 1;
	/*
	while (getline(std::cin, contact[i].first))
		if (contact[i].first != "")
		       	break;
	if (!check_empty(contact[i].first, 1))
		contact[i].set = 1;
	*/
}

int	main()
{
	Phonebook mycontact;
	std::string command;

	while (1)
	{
		std::cout << "===============================================" << std::endl;
		std::cout << "Enter a command..." << std::endl;
		std::cin >> command;
		std::cout << "===============================================" << std::endl;

		if (command.compare("SEARCH") == 0)
			mycontact.search();

		else if (command.compare("ADD") == 0)
			mycontact.add();
		else if (command.compare("EXIT") == 0) return 0;
		else std::cout << "COMMAND UNKNOWN.\tAvailable commands : ADD, SEARCH, EXIT" << std::endl;
	}
	return 0;
}
