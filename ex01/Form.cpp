/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:34:19 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/12 12:30:52 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
:	_name("Default"), _grade(150)
{
}

Form::Form(int grade)
:	_name("Generic")
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else if (grade >= 1 && grade <= 150)
	{
		this->_grade = grade;
	}
}

Form::Form(const Form& other)
	:	_name(other._name)
{
	*this = other;
}

Form::~Form(void)
{
}

void	Form::incrementGrade(void)
{
	if ((this->_grade - 1) < 1)
		throw GradeTooHighException();
	else if ((this->_grade - 1) >= 1)
	{
		this->_grade -= 1;
	}
}

void	Form::decrementGrade(void)
{
	if ((this->_grade + 1) > 150)
		throw GradeTooLowException();
	else if ((this->_grade + 1) <= 150)
	{
		this->_grade += 1;
	}
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

int	Form::getGrade(void) const
{
	return (this->_grade);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

Form& Form::operator=(const Form &other)
{
	if (this->_grade != other._grade)
		this->_grade = other._grade;
	return (*this);
}