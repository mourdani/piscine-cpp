#include "phonebook.hpp"

int Contact::add()
{
	static int i = 0;

	index = i + 1;
	// Information Input
	set = 0;
	while ((_first.empty() || set == 0))
	{
		std::cout << "First name: ";
		// get all input from std::cin
		while (getline(std::cin, _first))
			if (_first != "")
			       	break; if (_first.empty())
			return 1;	
		if (!check_empty(_first, 1))
			set = 1;
	}
	
	set = 0;
	while (_last.empty() || set == 0)
	{
		std::cout << "Last name: ";
		while (getline(std::cin, _last))
			if (_last != "")
				break;
		if (_last.empty()) return 1;	
		if (!check_empty(_last, 1))
			set = 1;
	}

	set = 0;
	while (_nick.empty() || set == 0)
	{
		std::cout << "Nickname: ";
		while (getline(std::cin, _nick))
			if (_nick != "") break;
		if (_nick.empty()) return 1;	
		if (!check_empty(_nick, 1)) set = 1;
	}
	
	set = 0;
	while (_secret.empty() || set == 0)
	{
		std::cout << "Darkest secret: ";
		while (getline(std::cin, _secret))
			if (_secret != "")	break;
		if (_secret.empty())		return 1;	
		if (!check_empty(_secret, 2))	set = 1;
	}

	set = 0;
	while (!_number || set == 0)
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
			set = 1;
	}
	std::cout << "saved at index " << index  << std::endl;
	i++;
	return 0;
}
