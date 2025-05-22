/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:50:41 by jose-gon          #+#    #+#             */
/*   Updated: 2025/05/22 22:23:31 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Bureaucrat.hpp>
#include <Form.hpp>

int main() {
    std::cout << "--- Bureaucrat Creation ---" << std::endl;
    try {
        Bureaucrat b1("Juan", 75);
        Bureaucrat b2("Ana", 1);    // highest allowed grade
        Bureaucrat b3("Pedro", 150); // lowest allowed grade

        std::cout << b1;
        std::cout << b2;
        std::cout << b3;
        std::cout << std::endl;

        std::cout << "--- Incrementing and Decrementing ---" << std::endl;
        b1.incrementGrade();
        std::cout << b1;
        b3.decrementGrade(); // should throw error
    }
    catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Form Creation ---" << std::endl;
    try {
        Form f1("Permission A", 120, 100);
        Form f2("Permission B", 1, 1); // high requirement
        std::cout << f1;
        std::cout << f2;

        std::cout << "\n--- Bureaucrats ---" << std::endl;
        
        Bureaucrat boss("Director", 1);
        Bureaucrat assistant("Assistant", 120);
        std::cout << boss;
        std::cout << assistant;

        std::cout << "\n--- Signing Forms ---" << std::endl;
        boss.signForm(f2);       // should sign
        assistant.signForm(f1);  // should sign
        assistant.signForm(f2);  // should fail

        std::cout << f1;
        std::cout << f2;
    }
    catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Invalid Creation (Expected Errors) ---" << std::endl;
    try {
        Bureaucrat invalid("Error1", 0);  // Too high
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Form invalidForm("ErrorForm", 151, 10);  // Invalid grade
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
