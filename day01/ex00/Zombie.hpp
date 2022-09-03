/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 06:03:55 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/03 06:28:32 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>


class Zombie
{
	public :
	
		std::string name;

		void	announce(void)
		{
			std::cout << name << ":" <<  "BraiiiiiiinnnzzzZ..." << std::endl;
		}
}; 

Zombie* newZombie(std::string name);
void    randomChump(std::string name);
