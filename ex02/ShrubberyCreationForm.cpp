/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 11:56:52 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/15 12:23:54 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->AForm::execute(executor) == true)
		return (true);
	return (false);
}