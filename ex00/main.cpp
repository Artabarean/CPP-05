/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:39:57 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/12 11:27:46 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}