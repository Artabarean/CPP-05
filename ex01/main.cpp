/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:39:57 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/14 12:55:44 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
		Form f("Form", 45, 20);
		std::cout << f << std::endl;
		signer.signForm(f);
		std::cout << f << std::endl;
		Form f2("Form2", 50, 70);
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