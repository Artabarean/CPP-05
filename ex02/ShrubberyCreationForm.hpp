/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 11:56:54 by atabarea          #+#    #+#             */
/*   Updated: 2026/05/15 12:20:05 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &);
		~ShrubberyCreationForm(void);
		void executeAction(void) const;
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	private:
		const std::string _target;
};
