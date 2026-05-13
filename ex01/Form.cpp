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
:	_name("Default form"), _reqtosign(1), _reqtoexec(1)
{
}

Form::Form(int grade)
:	_name("form"), _reqtosign(1), _reqtoexec(1)
{
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

std::string Form::getName(void)const
{
	return (this->_name);
}

void Form::besigned(const Bureaucrat &other)
{
	if (other.getGrade() < this->_reqtosign)
		throw GradeTooHighException();
	else if(other.getGrade() > this->_reqtosign)
		throw GradeTooLowException();
}

Form& Form::operator=(const Form &other)
{
	if (this->_isSigned != other._isSigned)
		this->_isSigned = other._isSigned;
	return (*this);
}

std::ostream& operator<<(std::ostream &os, const Form &other)
{
	os << other.getName() << std::endl;
	return (os);
}