/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:26:14 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/21 19:51:42 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat {
	public :

		// Constructor
		Bureaucrat(std::string name, int grade);

		// Exception Classes
		class GradeTooHighException : public std::exception {
			public :
				const char* what() const throw() {
					return "Grade too High !!\n";
				};

		
		};
		class GradeTooLowException  : public std::exception {
			public :
				const char* what() const throw() {
					return "Grade too Low !!\n";
				};
		
		};

		// Getters
		std::string 	getName() const;
		int 		getGrade() const;

		// Setters
		void		setName(std::string name);
		void		setGrade(int grade);

		// Incrementing functions
		void incrementGrade();
		void decrementGrade();

		// Surcharge d'operateur <<

	protected :
		std::string 	_name;
		int		_grade;	
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);


#endif
