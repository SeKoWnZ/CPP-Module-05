/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:08:59 by jose-gon          #+#    #+#             */
/*   Updated: 2025/06/12 10:54:17 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RobotomyRequestForm.hpp>

// RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises, then informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, it informs that the robotomy failed.

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{	
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& source) : AForm(source), _target(source._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& source)
{
	if (this != &source)
		AForm::operator=(source);
	return *this;
}

void RobotomyRequestForm::runForm() const
{
	std::srand(std::time(0));
	std::cout << "Kkrrrrrrr zzhhh (makes some drilling noises)." << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized!." << std::endl;
	else
		std::cout << "Robotomy on " << _target << " failed!." << std::endl;
}
