/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:57:02 by ipavlov           #+#    #+#             */
/*   Updated: 2025/09/10 11:23:38 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	
	std::cout << "=== Creating ClapTrap ===" << std::endl;
    ClapTrap clap("Koko");
    clap.attack("other dogs");

    std::cout << "\n=== Creating ScavTrap ===" << std::endl;
    ScavTrap scav("Chris");
    scav.attack("Koko");
    scav.gateKeeper();

    std::cout << "\n=== Copy and Assignment Test ===" << std::endl;
    ScavTrap scav2(scav);
    scav2.attack("target3");
    scav2.takeDamage(12);
    scav2.beRepaired(15);

    ScavTrap scav3("Another");
    scav3 = scav2;
    scav2.gateKeeper();

    std::cout << "\n=== Destructors Called ===" << std::endl;

    // {
    //     ClapTrap clap("Chris");
    //     ScavTrap scav("Chris");

    //     clap.attack("target3");
    //     scav.attack("target3");

    //     ClapTrap* poly = new ScavTrap("Chris");
    //     poly->attack("target3");
    //     delete poly;
    // }
	
	return 0;
}