/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 11:56:48 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/18 11:18:34 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->AForm::execute(executor) == true)
		return (true);
	return (false);
}
