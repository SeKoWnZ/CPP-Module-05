/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:50:41 by jose-gon          #+#    #+#             */
/*   Updated: 2025/05/19 21:55:17 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

int main() 
{
    std::cout << "== Creando burócratas válidos ==" << std::endl;
    Bureaucrat a("Alice", 42);
    Bureaucrat b("Bob", 1);
    Bureaucrat c("Charlie", 150);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    std::cout << "\n== Prueba de incremento y decremento ==" << std::endl;
    try {
        a.incrementGrade(); // 42 -> 41
        std::cout << "Incrementado: " << a << std::endl;
        c.decrementGrade(); // Excepción
    } catch (std::exception &e) {
        std::cout << "Excepción atrapada: " << e.what() << std::endl;
    }

    try {
        b.incrementGrade(); // Excepción (ya es 1)
    } catch (std::exception &e) {
        std::cout << "Excepción atrapada: " << e.what() << std::endl;
    }

    std::cout << "\n== Prueba de constructor inválido ==" << std::endl;
    try {
        Bureaucrat d("Dave", 0); // Excepción
    } catch (std::exception &e) {
        std::cout << "Excepción atrapada: " << e.what() << std::endl;
    }

    try {
        Bureaucrat e("Eve", 151); // Excepción
    } catch (std::exception &e) {
        std::cout << "Excepción atrapada: " << e.what() << std::endl;
    }

    std::cout << "\n== Prueba de copia y asignación ==" << std::endl;
    Bureaucrat f(a); // Constructor de copia
    std::cout << "Copia: " << f << std::endl;

    Bureaucrat g;
    g = c; // Operador de asignación
    std::cout << "Asignado: " << g << std::endl;

    return 0;
}
