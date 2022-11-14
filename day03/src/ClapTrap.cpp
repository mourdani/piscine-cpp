/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:37:13 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/14 18:39:17 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(): _hit_pts(10),  _energy_pts(10), _attack_dmg(0) {};
ClapTrap::ClapTrap(std::string name): _name(name), _hit_pts(10),  _energy_pts(10), _attack_dmg(0) {};; 
//ClapTrap::ClapTrap(const ClapTrap & cpy);
ClapTrap::~ClapTrap(){};

void ClapTrap::attack(const std::string &target) {
	// target	lose <attack_dmg>	hit.
	// *this	lose 1			energy.
}

void ClapTrap::takeDamage(unsigned int amount) {
	// *this	lose <amount>		hit.
}

void ClapTrap::beRepaired(unsigned int amount) {
	// *this	get <amount>		hit.
	// *this	lose 1			energy.
}
