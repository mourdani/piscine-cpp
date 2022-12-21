/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:25:52 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/21 19:55:34 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("John", 3);
        std::cout << b << std::endl;

        b.setGrade(151);  // This should throw an exception
        std::cout << b << std::endl;
    }

    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

