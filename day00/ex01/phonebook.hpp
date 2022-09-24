/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:14:57 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/24 20:55:40 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		int _index;
		int _set;
		std::string _first;
		std::string _last;
		std::string _nick;
		std::string _secret;
		int _number;

	public:
		Contact(void);
		int getIndex(void);
		int getSet(void);
		std::string getFirst(void);
		std::string getLast(void);
		std::string getNick(void);
		int getNumber(void);
		std::string getSecret(void);
		void setIndex(int n);
		void setSet(int n);
		void setFirst(std::string);
		void setLast(std::string);
		void setNick(std::string);
		void setNumber(int n);
		void setSecret(std::string);
		// Function to add a contact 
		int add();
		// Function to show phonebook and search an index
		int search();
};

class Phonebook
{
	public:
		Contact contact[8];
};

