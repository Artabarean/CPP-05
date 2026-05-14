/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:24:51 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/14 12:32:07 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; // forward declaration to avoid circular include

class AForm
{
	public:
		AForm(void);
		AForm(const std::string &name, int reqToSign, int reqToExec);
		AForm(const AForm&);
		~AForm(void);

		int            getReqtosign() const;
		int            getReqtoexec() const;
		std::string    getName() const;
		bool           isSigned() const;

		void        beSigned(const Bureaucrat&);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw();
		};

		AForm& operator=(const AForm&);
	private:
		const std::string    _name;
		bool                _isSigned;
		const int            _reqtosign;
		const int            _reqtoexec;
};

std::ostream& operator<<(std::ostream &os, const AForm &);