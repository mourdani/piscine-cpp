/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:46:28 by mourdani          #+#    #+#             */
/*   Updated: 2022/11/20 17:20:19 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Animal {
	protected :
		std::string _type;
	public :
		Animal(std::string type): _type(type) {};
		void makeSound() {std::cout << "Inaudible " << this->_type << " animal voice";}; 
};
