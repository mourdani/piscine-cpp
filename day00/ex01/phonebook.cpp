/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:48:09 by mourdani          #+#    #+#             */
/*   Updated: 2022/08/25 05:31:04 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <unistd.h>

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

class Contact
{
	public:
		int index;
		std::string first;
		std::string last;
		std::string nick;
		unsigned int number;
		std::string secret;

};

void print_empty(std::string str)
{
	if (str.empty())
	       std::cout << "Information can not be empty" << std::endl;
}

class Phonebook
{
	public:
		Contact contact[7];
		
		int add()
		{
			static int i = 0;
			
			while (contact[i].first.empty())
			{
				std::cout << "First name :" << std::endl;
				getline(std::cin, contact[i].first);
				getline(std::cin, contact[i].first);
				print_empty(contact[i].first);
			}

			while (contact[i].last.empty())
			{
				std::cout << "Last name :" << std::endl;
				getline(std::cin, contact[i].last);
				print_empty(contact[i].last);
			}

			while (contact[i].nick.empty())
			{
				std::cout << "Nickname :" << std::endl;
				getline(std::cin, contact[i].nick);
				print_empty(contact[i].nick);
			}

			while (contact[i].secret.empty())
			{
				std::cout << "Darkest secret :" << std::endl;

				getline(std::cin, contact[i].secret);
				
				print_empty(contact[i].secret);
			}			
			contact[i].number = 0;
			while (!contact[i].number)
			{
				std::cout << "Phone number :" << std::endl;
				std::cin >> contact[i].number;

				std::cout << "ur number :" << contact[i].number << std::endl;
				if (!contact[i].number) std::cout << "Number can't be empty" << std::endl;
			}
			contact[i].index = i;
			std::cout << "Contact saved at index " << contact[i].index  << std::endl;
			i++;
			std::cout << "============================================" << std::endl;
			return 0;
		}

		void	search(void)
		{
			int i = -1;
			std::cout << "|" << "  Index   " << "|" << "First name" << "|" << " Last name" << "|" << " Nickname " << "|" << std::endl;
			std::cout << "|__________|__________|__________|__________|" << std::endl;
			while (++i < 4)
			{
				std::cout	<< "|" << "         "
						<< contact[i].index  << "|" << ptrunk(contact[i].first)
						<< "|" <<  ptrunk(contact[i].last) << "|" << ptrunk(contact[i].nick)
						<< "|" << std::endl;
			}
			std::cout << "============================================" << std::endl;
		}

};





int	main()
{
	Phonebook mycontact;
	std::string add = "ADD";
	std::string search = "SEARCH";
	std::string exit = "EXIT";
	std::string command;

	while (1)
	{
		std::cout << "============================================" << std::endl;
		std::cout << "Enter a command..." << std::endl;
		std::cin >> command;
		std::cout << "============================================" << std::endl;
		if (command.compare(search) == 0)
			mycontact.search();
		else if (command.compare(add) == 0)
			mycontact.add();
		else if (command.compare(exit) == 0) return 0;
		else std::cout << "COMMAND UNKNOWN.\tAvailable commands : ADD, SEARCH, EXIT" << std::endl;
		{
		}
	}
	return 0;
}
