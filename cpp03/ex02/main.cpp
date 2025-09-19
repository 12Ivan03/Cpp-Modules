/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:56:58 by ipavlov           #+#    #+#             */
/*   Updated: 2025/09/10 16:49:28 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

	std::cout << "=== Creating ClapTrap ===" << std::endl;
    ClapTrap clap("Koko");
    clap.attack("other dogs");
    for (int i = 0; i < 12; i++)
        clap.attack("target3");
    clap.beRepaired(1);

    std::cout << "\n=== Creating ScavTrap ===" << std::endl;
    ScavTrap scav("Chris");
    scav.attack("Koko");
    scav.gateKeeper();

    std::cout << "\n=== Copy Test ===" << std::endl;
    ScavTrap scav2(scav);
    scav2.attack("target3");
    scav2.takeDamage(12);
    scav2.beRepaired(15);
    for (int i = 0; i < 50; i++)
        scav2.attack("target3");

    std::cout << "\n=== Assignment Test ===" << std::endl;
    ScavTrap scav3("Another");
    scav3 = scav2;
    scav3.gateKeeper();
    scav3.attack("someone");

    std::cout << "\n=== Create FragTrap ===" << std::endl;
	FragTrap frag("One");
    frag.takeDamage(42);
    frag.beRepaired(52);

    FragTrap frag007(frag);

    frag007.attack("Frager");
    frag007.attack("Frager123");
    frag007.attack("Frager321");
    frag007.attack("Frager231");
    frag007.attack("Frager132");
    // for (int i = 0; i < 100; i++)
    //     frag007.attack("Frager3");
    // frag007.attack("someone");
    frag007.takeDamage(1);
    
    std::cout << "\n=== Destructors Called ===" << std::endl;

	return 0;
}