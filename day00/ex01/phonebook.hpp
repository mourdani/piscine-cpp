/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:14:57 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/25 11:42:25 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <limits>

#define SLIM_LINE "_____________________________________________"
#define BOLD_LINE "==============================================="
#define COLUMNS "|__________|__________|__________|__________|"

int check_empty(std::string str, int mode);
std::string	ptrunk(std::string str);
bool check_number(std::string str);

// Attributes of a contact
class Contact
{
	private:
		std::string _first;
		std::string _last;
		std::string _nick;
		std::string _secret;
		int _number;

	public:
		int index;
		int set;
		std::string getFirst(void);
		std::string getLast(void);
		std::string getNick(void);
		std::string getSecret(void);
		int getNumber(void);

		void setFirst(std::string);
		void setLast(std::string);
		void setNick(std::string);
		void setNumber(int n);
		void setSecret(std::string);
		

		// Function to add a contact 
		int add();
};

class Phonebook
{
	public:
		Contact contact[8];

		// Function to show phonebook and search an index
		int search();
};

#endif
