/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:34:19 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/12 14:20:50 by atabarea         ###   ########.fr       */
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
	: _reqtosign(), _reqtoexec(), _name(other.getName())
{
	*this = other;
}

Form::~Form(void)
{
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

int	Form::getReqtosign(void)
{
	return (this->_reqtosign);
}

int	Form::getReqtoexec(void)
{
	return (this->_reqtoexec);
}

Form& Form::operator=(const Form &other)
{
	if (this->_isSigned != other._isSigned)
		this->_isSigned = other._isSigned;
	return (*this);
}