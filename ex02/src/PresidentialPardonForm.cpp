/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:10:17 by jose-gon          #+#    #+#             */
/*   Updated: 2025/06/12 10:53:43 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PresidentialPardonForm.hpp>

// • PresidentialPardonForm: Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{	
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& source) : AForm(source), _target(source._target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& source)
{
	if (this != &source)
		AForm::operator=(source);
	return *this;
}

void PresidentialPardonForm::runForm() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
