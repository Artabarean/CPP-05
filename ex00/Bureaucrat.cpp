/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:22:19 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/11 12:29:09 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
:	_name("Default"), _grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade)
:	_name("Generic")
{
	if (grade < 1)
		GradeTooHighException();
	else if (grade > 150)
		GradeTooLowException();
	else if (grade >= 1 && grade <= 150)
	{
		this->_grade = grade;
		std::cout << "Graded constructor called" << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	:	_name(other._name)
{
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called" << std::endl;
}

void	Bureaucrat::incrementGrade(Bureaucrat&)
{
	if ((this->_grade - 1) < 1)
		GradeTooHighException();
	else if ((this->_grade - 1) >= 1)
	{
		this->_grade -= 1;
		std::cout << "Grade incremented, current grade: " << this->_grade << std::endl;
	}
}

void	Bureaucrat::decrementGrade(Bureaucrat&)
{
	if ((this->_grade + 1) > 150)
		GradeTooLowException();
	else if ((this->_grade + 1) <= 150)
	{
		this->_grade += 1;
		std::cout << "Grade decremented, current grade: " << this->_grade << std::endl;
	}
}

void	Bureaucrat::GradeTooHighException(void)
{
	
}

void	Bureaucrat::GradeTooLowException(void)
{

}

int	Bureaucrat::getGrade(void)
{
	return (this->_grade);
}

std::string	Bureaucrat::getName(void)
{
	return (this->_name);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	this->_grade = other._grade;
	std::cout << "Copy assingnement operator called" << std::endl;
	return (*this);
}
