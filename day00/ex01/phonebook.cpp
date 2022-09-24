/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:23:24 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/24 20:59:02 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int Contact::getIndex(void){
	return (_index);
};
int Contact::getSet(void){
	return (_set);
};
std::string Contact::getFirst(void){
	return (_first);
};
std::string Contact::getLast(void){
	return (_last);
};
std::string Contact::getNick(void){
	return (_nick);
};
int Contact::getNumber(void){
	return (_number);
};
std::string Contact::getSecret(void){
	return (_secret);
};
void Contact::setIndex(int n){
	_index = n;
};
void Contact::setSet(int set){
	_set = set;
};
void Contact::setFirst(std::string str){
	_first = str;
};
void Contact::setLast(std::string str){
	_last = str;
};
void Contact::setNick(std::string str){
	_nick = str;
};
void Contact::setNumber(int n){
	_number = n;
};
void Contact::setSecret(std::string str){
	_secret = str;
};

/*
int add()
{
	static int i = 0;
	setindex = i + 1;
	
	// replace oldest contact with newest one

	// Information Input
	_set = 0;
	while ((_first.empty() || _set == 0))
	{
		std::cout << "First name: ";
		// get all input from std::cin
		while (getline(std::cin, _first))
			if (_first != "")
			       	break;
		if (_first.empty())
			return ;	
		if (!check_empty(_first, 1))
			_set = 1;
	}
	
	_set = 0;
	while (_last.empty() || _set == 0)
	{
		std::cout << "Last name: ";
		while (getline(std::cin, _last))
			if (_last != "")
				break;
		if (_last.empty())
			return ;	
		if (!check_empty(_last, 1))
			_set = 1;
	}

	_set = 0;
	while (_nick.empty() || _set == 0)
	{
		std::cout << "Nickname: ";
		while (getline(std::cin, _nick))
			if (_nick != "")
				break;
		if (_nick.empty())
			return ;	
		if (!check_empty(_nick, 1))
			_set = 1;
	}
	
	_set = 0;
	while (_secret.empty() || _set == 0)
	{
		std::cout << "Darkest _secret: ";
		while (getline(std::cin, _secret))
			if (_secret != "")
				break;
		if (_secret.empty())
			return ;	
		if (!check_empty(_secret, 2))
			_set = 1;
	}

	_set = 0;
	while (!_number || _set == 0)
	{
		std::cout << "Number: ";
		std::cin >> _number;
		if (!_number)
		{
			std::cout << "Number can only contains digits" << std::endl;
			// clear std::cin stream for new output
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			_set = 1;
	}
	std::cout << "saved at _index " << _index  << std::endl;
	return;
}
*
int	Contact::search(void)
{
	//int i = -1;
	int index = 0;

	// Search table output
	std::cout << SLIM_LINE << std::endl;
	std::cout << "|" << "  Index   "
	<< "|" << "First name" << "|" << " Last name"
	<< "|" << " Nickname " << "|" << std::endl;
	std::cout << COLUMNS << std::endl;
	while (set == 1)
	{
		std::cout	<< "|" << "         " << index
		<< "|" << ptrunk(first)
		<< "|" <<  ptrunk(last)
		<< "|" << ptrunk(_nick)
		<< "|" << std::endl;
	}
	std::cout << COLUMNS << std::endl << std::endl;

	// Index display output
	std::cout << "Enter the index of the to display :";
	std::cin >> index; 
	if (index <= 0 || index > 8 || set != 1 || !index) // check if index is not existent 
	{
		std::cout << "index non existent" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else
	{
		std::cout << SLIM_LINE << std::endl;
		std::cout << "First name: ";
		std::cout << "\t\t\t\t" <<  first << std::endl;
		std::cout <<  "Last name: ";
		std::cout << "\t\t\t\t" <<  last << std::endl;
		std::cout <<  "Nickname: ";
		std::cout << "\t\t\t\t" <<  nick << std::endl;
		std::cout <<  "Darkest secret: ";
		std::cout << "\t\t\t" <<  secret << std::endl;
		std::cout <<  "Number: ";
		std::cout << "\t\t\t\t" <<  number << std::endl;
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
		if ((str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ,.") != std::string::npos
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
*/
