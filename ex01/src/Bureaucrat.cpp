/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:35:19 by jose-gon          #+#    #+#             */
/*   Updated: 2025/05/22 22:05:19 by jose-gon         ###   ########.fr       */
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

Bureaucrat::Bureaucrat(Bureaucrat const& source)
{
	*this = source;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& source) {
	if (this != &source)
	{
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

void Bureaucrat::signForm(Form& source)
{
	try
	{
		source.beSigned(*this);
		std::cout << _name << " signed " << source.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		 std::cout << _name << " couldn's sign " << source.getName() << " because " << e.what() << std::endl;
	}
}
