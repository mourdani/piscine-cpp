/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:14:57 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/03 04:30:12 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include <unistd.h>
#include <sstream> 
#include <limits>

int check_empty(std::string str, int mode);
std::string	ptrunk(std::string str);
bool is_number(const std::string& s);
void	add_info(std::string str, int set);

class Contact
{
	public:
		int index;
		int set;
		std::string first;
		std::string last;
		std::string nick;
		int number;
		std::string secret;
};

class Phonebook
{
	public:
		Contact contact[8];
		
		int add()
		{
			static int i = 0;
			contact[i].index = i;
			if (i > 7) i = i % 8;
			contact[i].set = 0;

			while (contact[i].first.empty() || contact[i].set == 0)
			{
				std::cout << "First name: ";
				while (getline(std::cin, contact[i].first))
					if (contact[i].first != "")
					       	break;
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
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else
					contact[i].set = 1;
			}
			std::cout << "Contact saved at index " << contact[i++].index  << std::endl;
			return 0;
		}

		int	search(void)
		{
			int i = -1;
			int index = -1;


			std::cout << "_____________________________________________" << std::endl;
			std::cout << "|" << "  Index   "
			<< "|" << "First name" << "|" << " Last name"
			<< "|" << " Nickname " << "|" << std::endl;
			std::cout << "|__________|__________|__________|__________|" << std::endl;

			while (contact[++i].set == 1)
			{
				std::cout	<< "|" << "         " << contact[i].index
				<< "|" << ptrunk(contact[i].first)
				<< "|" <<  ptrunk(contact[i].last)
				<< "|" << ptrunk(contact[i].nick)
				<< "|" << std::endl;
			}
			std::cout << "|__________|__________|__________|__________|" << std::endl << std::endl;
			std::cout << "Enter the index of the contact to display :";
			std::cin >> index; 
			if (index == -1 || index > 7 || contact[index].set != 1)
			{
				std::cout << "index non existent" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
			{
				std::cout << "_____________________________________________" << std::endl;
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
};

