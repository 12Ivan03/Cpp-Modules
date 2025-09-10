/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:23:31 by ipavlov           #+#    #+#             */
/*   Updated: 2025/09/10 15:38:33 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {

	// ClapTrap clap {};
	ClapTrap clap("Someone");

	clap.attack("There");
	clap.attack("There w4e");
	clap.attack("There w4e");
	clap.attack("There w4e");
	clap.attack("There w4e");

	clap.takeDamage(3);
	clap.takeDamage(9);
	clap.takeDamage(9);

	clap.beRepaired(9);
	clap.beRepaired(9);
	clap.beRepaired(9);
	clap.beRepaired(9);
	clap.beRepaired(9);
	clap.beRepaired(9);
	clap.beRepaired(9);

	clap.attack("Something");

	return 0;
}