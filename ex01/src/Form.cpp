/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:51:45 by jose-gon          #+#    #+#             */
/*   Updated: 2025/05/22 22:11:31 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Form.hpp>

Form::Form() : _name("Unofficial"), _grade(150), _exec(150)
{
}

Form::Form(std::string str, int grd, int exec) : _name(str), _grade(grd), _exec(exec)
{
	_isSigned = false;
	if (grd < 1 || exec < 1)
		throw Form::GradeTooHighException();
	if (grd > 150 || exec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const& source) : _name(source._name), _grade(source._grade), _exec(source._exec)
{
	*this = source;
}

Form& Form::operator=(Form const& source)
{
	if (this != &source)
		_isSigned = source._isSigned;
	return *this;
}
Form::~Form()
{
}

std::string const& Form::getName() const
{
	return _name;
}

bool const& Form::getIsSigned() const
{
	return _isSigned;	
}

int const& Form::getGrade() const
{
	return _grade;
}

int const& Form::getExec() const
{
	return _exec;
}

void Form::beSigned(Bureaucrat const& source)
{
	{
		if (source.getGrade() <= _grade)
		{
			if (_isSigned == false)
				_isSigned = true;
			else
				throw Form::FormAlreadySigned();
		}
		else
			throw Form::GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& os, Form const& source)
{
	os << source.getName() << ", Form signing grade: " << source.getGrade() << ", Form execute grade: " << source.getExec() << ", Form signed status: " << source.getIsSigned() << std::endl;
	return os;
}