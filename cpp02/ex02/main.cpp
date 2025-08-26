/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:31:23 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/26 11:43:45 by ipavlov          ###   ########.fr       */
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

		//~~ Pre- ++a ~~//
		
		std::cout << "Increment LOOP" << std::endl;	
		Fixed ii(1.867f);
		std::cout << "Pre ++a:" << std::endl;
		while (ii < 2) {
			std::cout << "\t" << "i : ++" << ii << " = " << ++ii << std::endl << std::endl;
		}

		std::cout << "Pre ++a:" << std::endl;
		Fixed s(1);
		std::cout << "\t" << " ++" << s << " = " << ++s << std::endl << std::endl;
		Fixed t(2.998f);
		std::cout << "\t" << " ++" << t << " = " << ++t << std::endl << std::endl;
		
		//~~ Pre- --a ~~//

		std::cout << "Pre --a:" << std::endl;
		std::cout << "\t" << " " << s << " = " << --s << std::endl << std::endl;
		std::cout << "\t" << " --" << t << " = " << --t << std::endl << std::endl;

		//~~ Pre- a++ & a-- ~~//		

		std::cout << "Post a++:" << std::endl;
		Fixed u(23);
		std::cout << "\t" << u << "++" << " = " << u++ << std::endl << std::endl;
		Fixed v(42.998f);
		std::cout << "\t" << v << "--" << " = " << v-- << std::endl << std::endl;
	
		std::cout << "\t" << "Vlaue after incrementation: " << u << std::endl << std::endl;
		std::cout << "\t" << "Vlaue after decrementation: " << v << std::endl << std::endl;

		//~~ min + max ~~//		

		Fixed w(5);
		Fixed x( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << "min, max:" << std::endl;
		std::cout << "w: " << w << std::endl;
		std::cout << "x: " << x << std::endl;
		std::cout << Fixed::min(w , x) << std::endl;
		
		std::cout << "w: ++" << ++w << "x: ++" << ++x << std::endl;
		std::cout << Fixed::min(w , x) << std::endl;

		Fixed const y;
		Fixed const z( Fixed( 7.304f ) * Fixed( 3 ) );
		std::cout << "const min; const max:" << std::endl;
		std::cout << "y: " << y << std::endl;
		std::cout << "z: " << z << std::endl;
		std::cout << Fixed::min(y, z) << std::endl;

		Fixed aa(3.14159265359f);
		Fixed bb(2.71f);
		std::cout << Fixed::max(aa, bb) << std::endl << std::endl;
		
		std::cout << "Copy example from PDF subject" << std::endl << std::endl;
	
	}

	// PDF subject example suggestion. 
	{
		
		Fixed 			a;
		Fixed const 	b( Fixed( 5.05f ) * Fixed( 2 ) );
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		
		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
		
		return 0;
	}
	
	return 0;
}