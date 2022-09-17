/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:23:24 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/17 11:44:06 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"


int Phonebook::add()
{
	static int i = 0;
	contact[i].index = i;
	
	// replace oldest contact with newest one
	if (i > 7) i = i % 8;

	// Information Input
	contact[i].set = 0;
	while ((contact[i].first.empty() || contact[i].set == 0))
	{
		std::cout << "First name: ";
		// get all input from std::cin
		while (getline(std::cin, contact[i].first))
			if (contact[i].first != "")
			       	break;
		if (contact[i].first.empty())
			return 1;	
		if (!check_empty(contact[i].first, 1))
			contact[i].set = 1;
	}
	
	contact[i].set = 0;
	while (contact[i].last.empty() || contact[i].set == 0)
	{
		std::cout << "Last name: ";
		while (getline(std::cin, contact[i].last))
			if (contact[i].last != "")
				break;
		if (contact[i].last.empty())
			return 1;	
		if (!check_empty(contact[i].last, 1))
			contact[i].set = 1;
	}

	contact[i].set = 0;
	while (contact[i].nick.empty() || contact[i].set == 0)
	{
		std::cout << "Nickname: ";
		while (getline(std::cin, contact[i].nick))
			if (contact[i].nick != "")
				break;
		if (contact[i].nick.empty())
			return 1;	
		if (!check_empty(contact[i].nick, 1))
			contact[i].set = 1;
	}
	
	contact[i].set = 0;
	while (contact[i].secret.empty() || contact[i].set == 0)
	{
		std::cout << "Darkest secret: ";
		while (getline(std::cin, contact[i].secret))
			if (contact[i].secret != "")
				break;
		if (contact[i].secret.empty())
			return 1;	
		if (!check_empty(contact[i].secret, 2))
			contact[i].set = 1;
	}

	contact[i].set = 0;
	while (!contact[i].number || contact[i].set == 0)
	{
		std::cout << "Number: ";
		std::cin >> contact[i].number;
		if (!contact[i].number)
		{
			std::cout << "Number can only contains digits" << std::endl;
			// clear std::cin stream for new output
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			contact[i].set = 1;
	}
	std::cout << "Contact saved at index " << contact[i++].index  << std::endl;
	return 0;
}

int	Phonebook::search(void)
{
	int i = -1;
	int index = -1;

	// Search table output
	std::cout << SLIM_LINE << std::endl;
	std::cout << "|" << "  Index   "
	<< "|" << "First name" << "|" << " Last name"
	<< "|" << " Nickname " << "|" << std::endl;
	std::cout << COLUMNS << std::endl;
	while (contact[++i].set == 1)
	{
		std::cout	<< "|" << "         " << contact[i].index
		<< "|" << ptrunk(contact[i].first)
		<< "|" <<  ptrunk(contact[i].last)
		<< "|" << ptrunk(contact[i].nick)
		<< "|" << std::endl;
	}
	std::cout << COLUMNS << std::endl << std::endl;


	// Index display output
	std::cout << "Enter the index of the contact to display :";
	std::cin >> index; 
	if (index == -1 || contact[index].set != 1) // check if index is not existent 
	{
		std::cout << "index non existent" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else
	{
		std::cout << SLIM_LINE << std::endl;
		std::cout << "First name: ";
		std::cout << "\t\t\t\t" <<  contact[index].first << std::endl;
		std::cout <<  "Last name: ";
		std::cout << "\t\t\t\t" <<  contact[index].last << std::endl;
		std::cout <<  "Nickname: ";
		std::cout << "\t\t\t\t" <<  contact[index].nick << std::endl;
		std::cout <<  "Darkest secret: ";
		std::cout << "\t\t\t" <<  contact[index].secret << std::endl;
		std::cout <<  "Number: ";
		std::cout << "\t\t\t\t" <<  contact[index].number << std::endl;
	}
	return (0);
}

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

