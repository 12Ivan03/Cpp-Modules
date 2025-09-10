/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:57:02 by ipavlov           #+#    #+#             */
/*   Updated: 2025/09/10 15:52:16 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {

    // {
    //     ClapTrap clap("Koko");
    //     for (int i {0}; i < 10; i++)
    //         clap.attack("Other dogs");
    //     clap.attack("Other DOG");
    //     clap.takeDamage(10);
    //     clap.beRepaired(12);
            

    //     ScavTrap scav("Sass");
    //     for (int i {0}; i < 50; i++)
    //         scav.attack("Kaerb");
    //     scav.attack("Kaerb");
    //     scav.takeDamage(100);
    //     scav.beRepaired(12);
    // }
    
    {	
        std::cout << "=== Creating ClapTrap ===" << std::endl;
        ClapTrap clap("Koko");
        clap.attack("OtherDogs");

        std::cout << "\n=== Creating ScavTrap ===" << std::endl;
        ScavTrap scav("Chris");
        scav.attack("Koko");
        scav.gateKeeper();

        std::cout << "\n=== Copy and Assignment Test ===" << std::endl;
        ScavTrap scav2(scav);
        scav2.attack("Steeve");
        scav2.takeDamage(12);
        scav2.beRepaired(15);

        ScavTrap scav3("Another");
        scav3 = scav2;
        scav2.gateKeeper();

        std::cout << "\n=== Destructors Called ===" << std::endl;
    }
	
	return 0;
}
