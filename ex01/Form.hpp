/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:24:51 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/12 12:31:15 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

class Form
{
	public:
		Form(void);
		Form(int);
		Form(const Form&);
		~Form(void);
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