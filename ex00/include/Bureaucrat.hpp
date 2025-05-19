/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:50:34 by jose-gon          #+#    #+#             */
/*   Updated: 2025/05/19 21:47:56 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
# include <iostream>

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
		friend std::ostream& operator<<(std::ostream& os, Bureaucrat const& source);
		~Bureaucrat();
		
		std::string const& getName() const;
		int const & getgrade() const;

		void incrementGrade();
		void decrementGrade();
		
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
};

#endif