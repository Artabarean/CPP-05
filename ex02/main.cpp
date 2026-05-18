/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:28:46 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/18 12:55:07 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat b1(150);
		std::cout << b1;
		b1.incrementGrade();
		std::cout << b1;
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		Bureaucrat b2(1);
		std::cout << b2;
		b2.decrementGrade();
		std::cout << b2;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "---- Form signing tests ----" << std::endl;
	try
	{
		Bureaucrat signer(40);
		PresidentialPardonForm f("Form", 45, 20) ;
		std::cout << f << std::endl;
		signer.signForm(f);
		std::cout << f << std::endl;
		PresidentialPardonForm f2("Form2", 50, 70);
		Bureaucrat low(100);
		std::cout << f2 << std::endl;
		low.signForm(f2);
		std::cout << f2 << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	return (0);
}