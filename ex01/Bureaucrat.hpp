/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:22:17 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/12 11:16:35 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(int);
		Bureaucrat(const Bureaucrat&);
		~Bureaucrat(void);
		void		incrementGrade(void);
		void		decrementGrade(void);
		int			getGrade(void) const;
		std::string	getName(void) const;
		Bureaucrat& operator=(const Bureaucrat &);
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw();
		};
	
	private:
		const std::string 	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &);
