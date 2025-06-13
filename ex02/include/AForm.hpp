/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:50:55 by jose-gon          #+#    #+#             */
/*   Updated: 2025/05/22 21:55:01 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <Bureaucrat.hpp>

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _isSigned;
		int	const _grade;
		int const _exec;
		
	public:
		AForm();
		AForm(std::string str, int grd, int exec);
		AForm(AForm const& source);
		AForm& operator=(AForm const& source);
		virtual ~AForm();
		
		std::string const& getName() const;
		bool const& getIsSigned() const;
		int const& getGrade() const;
		int const& getExec() const;

		void beSigned(Bureaucrat const& source);
		
		void execute(Bureaucrat const& executor) const;
		bool checkExeGrade(Bureaucrat const& executor) const;
		virtual void runForm() const = 0;


		class GradeTooHighException : public std::exception
		{
			public:
			const char* what() const throw() {return "Error: Grade is too high.";};
		};
		class GradeTooLowException : public std::exception
		{
			public:
			const char* what() const throw() {return "Error: Grade is too low.";};
		};
		class AFormAlreadySigned : public std::exception
		{
			public:
			const char* what() const throw() {return "Error: Form is already signed.";};
		};
		class AFormNotSigned : public std::exception
		{
			public:
			const char* what() const throw() {return "Error: Form cannot be executed without a signature";};
		};
		friend std::ostream& operator<<(std::ostream& os, AForm const& source);
};

#endif
