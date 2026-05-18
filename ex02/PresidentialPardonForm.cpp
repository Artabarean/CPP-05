/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 11:56:43 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/18 12:32:09 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &name, int reqToSign, int reqToExec)
{
	
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->AForm::execute(executor) == true)
		return (true);
	return (false);
}
