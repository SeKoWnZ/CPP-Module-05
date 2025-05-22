/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:50:34 by jose-gon          #+#    #+#             */
/*   Updated: 2025/05/22 21:55:30 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <Form.hpp>

class Form;

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
		void signForm(Form& source);
		
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