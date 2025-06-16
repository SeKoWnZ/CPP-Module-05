/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:50:41 by jose-gon          #+#    #+#             */
/*   Updated: 2025/06/13 10:04:06 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <Bureaucrat.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

int main() 
{
	{
		std::cout << std::endl << std::setw(40) << "--- Presidential Form Creation ---" << std::endl;
		PresidentialPardonForm Presi("Sebastian");

		std::cout << Presi;

		std::cout << std::endl << std::setw(40) << "--- Bureaucrats For Presidential---" << std::endl;

		Bureaucrat boss("Director", 1);
		Bureaucrat sub("Subdirector", 20);
		Bureaucrat infra("Infradirector", 26);

		std::cout << boss;
		std::cout << sub;
		std::cout << infra;

		std::cout << std::endl << std::setw(40) << "--- Signing Presidential Forms ---" << std::endl;
		infra.signAForm(Presi);  // should fail
		sub.signAForm(Presi);  // should sign
		boss.signAForm(Presi); // should fail already signed

		std::cout << Presi;

		std::cout << std::endl << std::setw(40) << "--- Executing Presidential Forms ---" << std::endl;
		try
		{
			infra.executeForm(Presi); // should fail
		}
		catch (std::exception& e)
		{
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
		try
		{
			sub.executeForm(Presi); // should fail
		}
		catch (std::exception& e)
		{
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
		try
		{
			boss.executeForm(Presi); // should fail
		}
		catch (std::exception& e)
		{
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << std::setw(40) << "--- Robotomy Form Creation ---" << std::endl;
		RobotomyRequestForm Robo("Braniac");

		std::cout << Robo;

		std::cout << std::endl << std::setw(40) << "--- Bureaucrats For Robotomy---" << std::endl;

		Bureaucrat patien("Patient", 40);
		Bureaucrat medic("Medic", 50);
		Bureaucrat celator("Celator", 100);

		std::cout << patien;
		std::cout << medic;
		std::cout << celator;

		std::cout << std::endl << std::setw(40) << "--- Signing Robotomy Forms ---" << std::endl;
		celator.signAForm(Robo);  // should fail
		medic.signAForm(Robo);  // should sign
		patien.signAForm(Robo); // should fail already signed

		std::cout << Robo;

		std::cout << std::endl << std::setw(40) << "--- Executing Robotomy Forms ---" << std::endl;
		try
		{
			celator.executeForm(Robo); // should fail
		}
		catch (std::exception& e)
		{
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
		try
		{
			medic.executeForm(Robo); // should fail
		}
		catch (std::exception& e)
		{
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
		try
		{
			patien.executeForm(Robo);// should fail
		}
		catch (std::exception& e)
		{
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl << std::setw(40) << "--- Shrubbery Form Creation ---" << std::endl;
		ShrubberyCreationForm shru("Shrubbery");

		std::cout << shru;

		std::cout << std::endl << std::setw(40) << "--- Bureaucrats For Shrubbery---" << std::endl;

		Bureaucrat garden("Gardener", 130);
		Bureaucrat hel("Helper", 140);
		Bureaucrat man("Normal Man", 150);

		std::cout << garden;
		std::cout << hel;
		std::cout << man;

		std::cout << std::endl << std::setw(40) << "--- Signing Shrubbery Forms ---" << std::endl;
		man.signAForm(shru);  // should fail
		hel.signAForm(shru);  // should sign
		garden.signAForm(shru); // should fail already signed

		std::cout << shru;

		std::cout << std::endl << std::setw(40) << "--- Executing Shrubbery Forms ---" << std::endl;
		try
		{
			man.executeForm(shru); // should fail
		}
		catch (std::exception& e)
		{
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
		try
		{
			hel.executeForm(shru); // should fail
		}
		catch (std::exception& e)
		{
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
		try
		{
			garden.executeForm(shru); // should fail
		}
		catch (std::exception& e)
		{
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}

    std::cout << std::endl << std::setw(50) << "--- Invalid Creation (Expected Errors) ---" << std::endl;
    try {
        Bureaucrat invalid("Error1", 0);  // Too high
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
