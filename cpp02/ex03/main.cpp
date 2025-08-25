/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:54:38 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/25 17:29:52 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {

	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);


	// Strict inside
	if (bsp(a, b, c, Point(2.0f, 2.0f)))
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

		
	// // On edge -> outside per subject
	// if (bsp(a, b, c, Point(5.0f, 0.0f)))
	// 	std::cout << "true" << std::endl;
	// else
	// 	std::cout << "false" << std::endl;
	// // On vertex -> outside
	// bsp(a, b, c, Point(0.0f, 0.0f));
	// // Outside
	// bsp(a, b, c, Point(7.0f, 7.0f));
	
	return 0;
}