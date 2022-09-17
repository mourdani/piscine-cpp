/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:14:57 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/17 11:25:49 by mourdani         ###   ########.fr       */
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

// Attributes of a contact
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
		
		// Function to add a contact 
		int add();
		int search();
};

