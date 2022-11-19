/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:37:08 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/19 09:02:22 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"


class ScavTrap : public ClapTrap {
	public :
		void guardGate();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap & cpy);
		ScavTrap &operator=(const ScavTrap & cpy);
		~ScavTrap();

		void attack(const std::string &target);
};
