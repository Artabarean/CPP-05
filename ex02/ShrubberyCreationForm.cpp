/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 11:56:52 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/27 14:11:35 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void ShrubberyCreationForm::executeAction(void) const
{
	std::ofstream out((this->_target + "_shrubbery").c_str());
	if (!out.is_open())
		throw GradeTooLowException();
	out << "       ccee88oo" << std::endl;
	out << "   C8O8O8Q8PoOb o8oo" << std::endl;
	out << "  dOB69QO8PdUOpugoO9bD" << std::endl;
	out << " CjjjbU8OU qOp qOdoUOdcb" << std::endl;
	out << "    6OuU  /p u gcoUodpP" << std::endl;
	out << "      \\////\\\\" << std::endl;
	out << "          ||" << std::endl;
	out << "          ||" << std::endl;
	out.close();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return (*this);
	return (*this);
}
