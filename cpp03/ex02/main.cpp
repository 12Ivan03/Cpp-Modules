/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:56:58 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/29 11:56:59 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	FragTrap frag("One");
    frag.takeDamage(40);

    FragTrap frag007(frag);

    frag007.attack("frag");
    frag007.attack("frag123");
    frag007.attack("frag321");
    frag007.attack("frag231");
    frag007.attack("frag132");
    

    std::cout << "\n=== Destructors Called ===" << std::endl;

	return 0;
}