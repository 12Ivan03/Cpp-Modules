/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:14:09 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/22 10:25:49 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() {

	Fixed a;
	Fixed const b( 1032454 );
	Fixed const c( 42.42345f );
	Fixed const d( b );
	Fixed const e( 42.42f );
	Fixed const f( 10 );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << d << std::endl;
	std::cout << "f is " << e << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "e is " << d.toInt() << " as integer" << std::endl;
	std::cout << "f is " << e.toInt() << " as integer" << std::endl;
	
	return 0;
}