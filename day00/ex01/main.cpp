/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:48:09 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/10 15:10:22 by mourdani         ###   ########.fr       */
/*   Updated: 2022/09/17 11:27:02 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

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
