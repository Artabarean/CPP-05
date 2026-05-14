/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:34:19 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/14 12:25:24 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void)
: _name("Default form"), _isSigned(false), _reqtosign(150), _reqtoexec(150)
{
}

Form::Form(const std::string &name, int reqToSign, int reqToExec)
: _name(name), _isSigned(false), _reqtosign(reqToSign), _reqtoexec(reqToExec)
{
	if (_reqtosign < 1 || _reqtoexec < 1)
		throw GradeTooHighException();
	if (_reqtosign > 150 || _reqtoexec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
: _name(other._name), _isSigned(other._isSigned), _reqtosign(other._reqtosign), _reqtoexec(other._reqtoexec)
{
}

Form::~Form(void)
{
}

const char*    Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char*    Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

int    Form::getReqtosign(void) const
{
	return (this->_reqtosign);
}

int    Form::getReqtoexec(void) const
{
	return (this->_reqtoexec);
}

std::string Form::getName(void) const
{
	return (this->_name);
}

bool Form::isSigned(void) const
{
	return (this->_isSigned);
}

void Form::beSigned(const Bureaucrat &other)
{
	if (other.getGrade() <= this->_reqtosign)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
	{
		// only _isSigned can be assigned, the other members are const
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream &os, const Form &other)
{
	os << "Form: " << other.getName() << ", signed: ";
	if (other.isSigned() == true)
		os << "yes";
	else
		os << "no";
	os	<< ", sign grade: " << other.getReqtosign() << ", exec grade: " << other.getReqtoexec();
	return (os);
}
