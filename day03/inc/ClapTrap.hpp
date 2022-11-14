/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:37:08 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/14 16:44:21 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>


class ClapTrap {
	private :
		std::string 	_name;
		int		_hit_pts;
		int		_energy_pts;
		int		_attack_dmg;
	
	public :
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap & cpy);
		~ClapTrap();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
}
