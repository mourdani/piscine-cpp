/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:35:39 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/21 19:54:10 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

// Constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}
/*
// Exception Classes
Bureaucrat::GradeTooHighException::GradeTooHighException() {
	std::cerr << "Grade too High !!\n";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {
	std::cerr << "Grade too Low !!\n";
}
*/
// Getters 
std::string 	Bureaucrat::getName() const {return this->_name;}
int		Bureaucrat::getGrade() const {return this->_grade;}

// Setters
void		Bureaucrat::setName(std::string name) {this->_name = name;}
void		Bureaucrat::setGrade(int grade) {
	if (grade > 150)
		throw GradeTooHighException();
	else if (grade < 1)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

// Incrementation functions
void Bureaucrat::incrementGrade() {this->_grade -=1;}
void Bureaucrat::decrementGrade() {this->_grade +=1;}

// Overloaded operator << 
std::ostream &operator<< (std::ostream &out, const Bureaucrat &bureaucrat) {
	out << "Buraucrat " << bureaucrat.getName() << ", grade : " << bureaucrat.getGrade() << std::endl;
	return out;
}
