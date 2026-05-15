/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:22:19 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/15 11:54:35 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void)
:	_name("Bureaucrat"), _grade(150)
{
}

Bureaucrat::Bureaucrat(int grade)
:	_name("Bureaucrat")
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

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	:	_name(other._name)
{
	*this = other;
}

Bureaucrat::~Bureaucrat(void)
{
}

void	Bureaucrat::incrementGrade(void)
{
	if ((this->_grade - 1) < 1)
		throw GradeTooHighException();
	else if ((this->_grade - 1) >= 1)
	{
		this->_grade -= 1;
	}
}

void	Bureaucrat::decrementGrade(void)
{
	if ((this->_grade + 1) > 150)
		throw GradeTooLowException();
	else if ((this->_grade + 1) <= 150)
	{
		this->_grade += 1;
	}
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	if (form.execute(*this) == true)
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	else
		std::cout << this->_name << " could not execute " << form.getName() << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this->_grade != other._grade)
		this->_grade = other._grade;
	return (*this);
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return (os);
}

void	Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << ex.what() << std::endl;
	}
}
