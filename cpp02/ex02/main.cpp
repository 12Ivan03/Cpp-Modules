/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:31:23 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/22 17:59:56 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	
	{
		Fixed a;
		Fixed b(42.42f);
		Fixed c(100);
		
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
		
		//~~ Addition ~~//
		std::cout << std::endl << "Addition:" << std::endl;
		Fixed d(c + b);
		std::cout << "\t" << c << " + " << b << " = " << d << std::endl << std::endl;

		//~~ Subtraction ~~//
		std::cout << "Subtraction:" << std::endl;
		Fixed e(1.42f);
		Fixed f(b - e);
		std::cout << "\t" << b << " - " << e << " = " << f << std::endl << std::endl;
		Fixed g(86.42f);
		Fixed h(e - g);
		std::cout << "\t" << e << " - " << g << " = " << h << std::endl << std::endl;
		

		//~~ Multiplication ~~//
		
		std::cout << "Multiplication:" << std::endl;
		Fixed i(23.56f);
		Fixed j(5431);
		std::cout << "\t" << i << " * " << j << " = " << i * j << std::endl << std::endl;
		Fixed k(8);
		Fixed l(7);
		Fixed m(k * l);
		std::cout << "\t" << k << " * " << l << " = " << m << std::endl << std::endl;


		//~~ Division ~~//
		std::cout << "Devision:" << std::endl;
		Fixed n(1.5f);
		Fixed o(2.5f);
		std::cout << "\t" << n << " / " << o << " = " << n / o << std::endl << std::endl;
		Fixed p(8);
		Fixed q(7);
		Fixed r(p / q);
		std::cout << "\t" << p << " / " << q << " = " << r << std::endl << std::endl;

	}

	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		// std::cout << ++a << std::endl;
		// std::cout << a << std::endl;
		// std::cout << a++ << std::endl;
		// std::cout << a << std::endl;
		std::cout << b << std::endl;
		// std::cout << Fixed::max( a, b ) << std::endl;
	}
	
	return 0;
}