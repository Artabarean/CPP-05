/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:22:17 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/11 12:08:17 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(int);
		Bureaucrat(const Bureaucrat&);
		~Bureaucrat(void);
		void		incrementGrade(Bureaucrat&);
		void		decrementGrade(Bureaucrat&);
		void		GradeTooHighException(void);
		void		GradeTooLowException(void);
		int			getGrade(void);
		std::string	getName(void);
		Bureaucrat& operator=(const Bureaucrat &);
	
	private:
		const std::string 	_name;
		int					_grade;
};
