/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:50:55 by jose-gon          #+#    #+#             */
/*   Updated: 2025/05/22 21:55:01 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <Bureaucrat.hpp>

class Bureaucrat;
class Form
{
	private:
		std::string const _name;
		bool _isSigned;
		int	const _grade;
		int const _exec;
		
	public:
		Form();
		Form(std::string str, int grd, int exec);
		Form(Form const& source);
		Form& operator=(Form const& source);
		~Form();
		
		std::string const& getName() const;
		bool const& getIsSigned() const;
		int const& getGrade() const;
		int const& getExec() const;

		void beSigned(Bureaucrat const& source);

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
		class FormAlreadySigned : public std::exception
		{
			public:
			const char* what() const throw() {return "Error: Form is already signed.";};
		};
		friend std::ostream& operator<<(std::ostream& os, Form const& source);
};

#endif
