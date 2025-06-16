/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:50:34 by jose-gon          #+#    #+#             */
/*   Updated: 2025/06/12 12:24:46 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <AForm.hpp>

// Lastly, add the executeForm(AForm const & form) member function to the Bureau-
// crat class. It must attempt to execute the form. If successful, print something like:
// <bureaucrat> executed <form>
// If not, print an explicit error message.
// Implement and submit some tests to ensure everything works as expected.

class AForm;

class Bureaucrat
{
	private:
		std::string const _name;
		int	_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string str, int val);
		Bureaucrat(Bureaucrat const& source);
		Bureaucrat& operator=(Bureaucrat const& source);
		~Bureaucrat();
		
		std::string const& getName() const;
		int const & getGrade() const;
		
		void incrementGrade();
		void decrementGrade();
		void signAForm(AForm& source);
		void executeForm(AForm const & form) const;
		
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
		friend std::ostream& operator<<(std::ostream& os, Bureaucrat const& source);
};

#endif
