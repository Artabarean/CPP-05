/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:34:19 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/15 11:44:45 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void)
: _name("Default Form"), _isSigned(false), _reqtosign(150), _reqtoexec(150)
{
}

AForm::AForm(const std::string &name, int reqToSign, int reqToExec)
: _name(name), _isSigned(false), _reqtosign(reqToSign), _reqtoexec(reqToExec)
{
	if (_reqtosign < 1 || _reqtoexec < 1)
		throw GradeTooHighException();
	if (_reqtosign > 150 || _reqtoexec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
: _name(other._name), _isSigned(other._isSigned), _reqtosign(other._reqtosign), _reqtoexec(other._reqtoexec)
{
}

AForm::~AForm(void)
{
}

const char*    AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char*    AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

int    AForm::getReqtosign(void) const
{
	return (this->_reqtosign);
}

int    AForm::getReqtoexec(void) const
{
	return (this->_reqtoexec);
}

std::string AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::isSigned(void) const
{
	return (this->_isSigned);
}

void AForm::beSigned(const Bureaucrat &other)
{
	if (other.getGrade() <= this->_reqtosign)
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

bool AForm::execute(Bureaucrat const & executor) const
{
	if (this->_isSigned == true && executor.getGrade() <= this->_reqtoexec)
		return (true);
	else
		throw GradeTooLowException();
	return (false);
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		// only _isSigned can be assigned, the other members are const
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream &os, const AForm &other)
{
	os << "Form: " << other.getName() << ", signed: ";
	if (other.isSigned() == true)
		os << "yes";
	else
		os << "no";
	os	<< ", sign grade: " << other.getReqtosign() << ", exec grade: " << other.getReqtoexec();
	return (os);
}
