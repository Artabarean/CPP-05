/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:28:46 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/27 11:05:07 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	try
	{
		Bureaucrat signer(40);
		PresidentialPardonForm f("home") ;
		std::cout << f << std::endl;
		signer.signForm(f);
		std::cout << f << std::endl;
		signer.executeForm(f);

		Bureaucrat boss(1);
		PresidentialPardonForm f_success("home-office");
		boss.signForm(f_success);
		boss.executeForm(f_success);

		Bureaucrat low(100);
		RobotomyRequestForm f2("marvin");
		std::cout << f2 << std::endl;
		low.signForm(f2);
		std::cout << f2 << std::endl;
		low.executeForm(f2);

		Bureaucrat robot(1);
		RobotomyRequestForm f3("marvin");
		robot.signForm(f3);
		robot.executeForm(f3);

		ShrubberyCreationForm f4("garden");
		Bureaucrat gardener(1);
		gardener.signForm(f4);
		gardener.executeForm(f4);
	}
	catch (std::exception &ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete (rrf);
	return (0);
}
