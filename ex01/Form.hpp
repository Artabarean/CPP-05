/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:24:51 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/12 14:17:48 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form(void);
		Form(int);
		Form(const Form&);
		~Form(void);
		int			getReqtosign();
		int			getReqtoexec();
		std::string	getName()const;
		void		besigned(const Bureaucrat&);
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw();
		};
		Form& operator=(const Form&);
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_reqtosign;
		const int			_reqtoexec;
};

std::ostream& operator<<(std::ostream &os, const Form &);