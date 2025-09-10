/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:23:31 by ipavlov           #+#    #+#             */
/*   Updated: 2025/09/10 11:10:08 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {

	ClapTrap clap("hi");

	clap.attack("there");
	clap.attack("there w4e");
	clap.attack("there w4e");
	clap.attack("there w4e");
	clap.attack("there w4e");

	clap.takeDamage(3);
	// clap.takeDamage(9);
	// clap.takeDamage(9);

	clap.beRepaired(9);
	clap.beRepaired(9);
	clap.beRepaired(9);
	clap.beRepaired(9);
	clap.beRepaired(9);
	clap.beRepaired(9);
	clap.beRepaired(9);

	return 0;
}