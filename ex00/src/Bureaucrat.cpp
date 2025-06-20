/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:35:19 by jose-gon          #+#    #+#             */
/*   Updated: 2025/05/21 19:37:47 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat() : _name("null"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string str, int val) : _name(str)
{
	if (val < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (val > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = val;
}
	// try
	// {
	// 	if (val < 1)
	// 		Bureaucrat::GradeTooHighException();
	// 	else if (val > 150)
	// 		Bureaucrat::GradeTooLowException();
	// 	else
	// 		_grade = val;
	// }
	// catch (std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// 	_grade = 150;
	// }
// }

Bureaucrat::Bureaucrat(Bureaucrat const& source) : _name(source._name)
{
	*this = source;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& source) {
	if (this != &source) {
		this->_grade = source._grade;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& source)
{
	os << source.getName() << ", bureaucrat grade " << source.getGrade() << std::endl;
	return os;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "DESTROYING: " << _name << std::endl;
}

std::string const& Bureaucrat::getName() const
{
	return _name;
}


int const & Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	try
	{
		if (_grade == 1)
			throw Bureaucrat::GradeTooHighException();
		_grade--;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		if (_grade == 150)
			throw Bureaucrat::GradeTooLowException();
		_grade++;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
