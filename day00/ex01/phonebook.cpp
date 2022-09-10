/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:48:09 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/10 15:10:22 by mourdani         ###   ########.fr       */
/*   Updated: 2022/08/28 20:54:02 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

// right aligns and truncs the output to fit the SEARCH table.
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

// mode 1 : checks if only small cap letters are found and retuns 1 if false;
// mode 2 : checks if not empty and not only whitespaces and returns 1 if false;
// both return 0 if true.
int	check_empty(std::string str, int mode)
{
	if (mode == 1)
	{
		if (str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos
			|| str.empty())    
		{
			std::cout << "Input can only contain alphabets" << std::endl;
			std::cin.clear();
			return 1;
		}
	}
	else if (mode == 2)
	{
		if ((str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos
			&& str.find_first_not_of(" \t") == std::string::npos) || str.empty())
		{
			std::cout << "Input can not be empty" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return 1;
		}
	}
	return 0;
}

int	main()
{
	// Phonebook is a class containing 8 contacts. mycontact[7]; 
	// command is the input command;
	Phonebook mycontact;
	std::string command;

	while (std::cin)
	{
		std::cout << BOLD_LINE << std::endl;
		std::cout << "Enter a command..." << std::endl;
		std::cin >> command;
		std::cout << BOLD_LINE << std::endl;

		// Execute function according to the inputed command
		if (command.compare("SEARCH") == 0)
		{
			if(mycontact.search())
				break;
		}
		else if (command.compare("ADD") == 0)
			mycontact.add();

		else if (command.compare("EXIT") == 0) return 0;

		else std::cout << "COMMAND UNKNOWN.\tAvailable commands : ADD, SEARCH, EXIT" << std::endl;
	}
	return 0;
}
