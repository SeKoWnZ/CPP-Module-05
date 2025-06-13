/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:51:45 by jose-gon          #+#    #+#             */
/*   Updated: 2025/05/26 17:28:16 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AForm.hpp>

AForm::AForm() : _name("Unofficial"), _grade(150), _exec(150)
{
}

AForm::AForm(std::string str, int grd, int exec) : _name(str), _grade(grd), _exec(exec)
{
	_isSigned = false;
	if (grd < 1 || exec < 1)
		throw AForm::GradeTooHighException();
	if (grd > 150 || exec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const& source) : _name(source._name), _grade(source._grade), _exec(source._exec)
{
	*this = source;
}

AForm& AForm::operator=(AForm const& source)
{
	if (this != &source)
		_isSigned = source._isSigned;
	return *this;
}
AForm::~AForm()
{
}

std::string const& AForm::getName() const
{
	return _name;
}

bool const& AForm::getIsSigned() const
{
	return _isSigned;	
}

int const& AForm::getGrade() const
{
	return _grade;
}

int const& AForm::getExec() const
{
	return _exec;
}

void AForm::beSigned(Bureaucrat const& source)
{
	{
		if (source.getGrade() <= _grade)
		{
			if (_isSigned == false)
				_isSigned = true;
			else
				throw AForm::AFormAlreadySigned();
		}
		else
			throw AForm::GradeTooLowException();
	}
}

bool AForm::checkExeGrade(Bureaucrat const& executor) const
{
	if (_exec < executor.getGrade())
		return false;
	return true;
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (_isSigned == false)
		throw AForm::AFormNotSigned();
	if (checkExeGrade(executor))
		runForm();
	else
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, AForm const& source)
{
	os << source.getName() << ", signing grade: " << source.getGrade() << ", execute grade: " << source.getExec() << ", signed status: " << source.getIsSigned() << std::endl;
	return os;
}
