/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 06:56:18 by mourdani          #+#    #+#             */
/*   Updated: 2022/09/30 18:21:55 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {}

const std::string &Weapon::getType()
{
	std::string &type = _type;
	return type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}
