/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 02:37:30 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/30 19:25:00 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
	public:
		void attack(void);
		HumanA(std::string name, Weapon weapon);
		~HumanA(){};

	private:
		std::string _name;
		Weapon _weapon;

};
