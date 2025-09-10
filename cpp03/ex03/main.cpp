/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:56:58 by ipavlov           #+#    #+#             */
/*   Updated: 2025/09/10 16:24:56 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void banner(const std::string& title) {
    std::cout << "\n==================================================\n"
              << title << "\n==================================================\n\n";
}

void spamAttacks(ClapTrap& c, const std::string& target, int times) {
    for (int i = 0; i < times; ++i) c.attack(target);
}

void spamRepairs(ClapTrap& c, unsigned int amount, int times) {
    for (int i = 0; i < times; ++i) c.beRepaired(amount);
}

int main() {

    banner("01) Construction order + whoAmI + special abilities");
    {
        DiamondTrap d1("DiaOne");             
        d1.whoAmI();                          
        d1.highFivesGuys();                   
        d1.attack("dummy");           
	}

    // banner("02) Stat mix check (HP=100 from Frag, EP=50 from Scav, AD=30 from Frag)");
    // {
    //     DiamondTrap d("Mixer");

	// 	for (int i = 0; i < 5; ++i) {
	// 		d.attack("Target");
	// 	};

    //     d.beRepaired(5);        

    //     DiamondTrap fresh("Fresh");
    //     fresh.takeDamage(99);
    //     fresh.attack("dummy");
    //     fresh.takeDamage(1);
    //     fresh.attack("dummy");
    //     fresh.beRepaired(10);
    // }

    // banner("03) Copy constructor: deep copy & independence");
    // {
    //     DiamondTrap a("Alpha");
    //     spamAttacks(a, "dummy", 10);

    //     DiamondTrap b(a); 

    //     spamAttacks(b, "dummy", 5);

    //     a.whoAmI();
    //     b.whoAmI();
    // }

    // banner("04) Copy assignment: deep copy & self-assignment safety");
    // {
    //     DiamondTrap c1("Charlie");
    //     DiamondTrap c2("C2");
    //     spamAttacks(c1, "dummy", 49);

    //     c2 = c1;
    //     c2.attack("dummy");

    //     c2 = c2;
    //     c2.attack("dummy"); 
    // }	
    
    // banner("05) Multiple instances: no shared static-like behavior");
    // {
    //     DiamondTrap d1("D1");
    //     DiamondTrap d2("D2");
        
    //     spamAttacks(d1, "tgt", 5);
        
    //     for (int i = 0; i < 3; ++i){
    //         d2.attack("tgt");
    //     };
    //     std::cout << "\nIf d1 and d2 behave independently, you're not using static for HP/EP/AD.\n";
    // }
    
    // banner("06) Edge cases + robustness");
    // {
    //         DiamondTrap e("Edge");
    //         spamAttacks(e, "dummy", 60);
    //         e.beRepaired(5);
    //         e.attack("dummy");
        
    //     e.takeDamage(1000);
    //     e.attack("dummy");
    //     e.beRepaired(100);
    // }
    
    return 0;
}