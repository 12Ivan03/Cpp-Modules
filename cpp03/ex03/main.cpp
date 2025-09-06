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

#include "DiamondTrap.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

static void banner(const std::string& title) {
    std::cout << "\n==================================================\n"
              << title << "\n==================================================\n\n";
}

// Try to burn energy by spamming attacks
static void spamAttacks(ClapTrap& c, const std::string& target, int times) {
    for (int i = 0; i < times; ++i) c.attack(target);
}

// Try to repair repeatedly (this will consume energy too)
static void spamRepairs(ClapTrap& c, unsigned int amount, int times) {
    for (int i = 0; i < times; ++i) c.beRepaired(amount);
}

int main() {

    // banner("01) Construction order + whoAmI + special abilities");
    // {
    //     DiamondTrap d1("DiaOne");             
    //     d1.whoAmI();                          
    //     d1.highFivesGuys();                   
    //     d1.attack("dummy");                   
	// }

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

    banner("04) Copy assignment: deep copy & self-assignment safety");
    {
        DiamondTrap c1("Charlie");
        DiamondTrap c2("C2");
        spamAttacks(c1, "dummy", 49);

        c2 = c1;
        c2.attack("dummy");

        c2 = c2;
        c2.attack("dummy"); 
    }

	
    banner("Done.");
    return 0;
}
// banner("05) Multiple instances: no shared static-like behavior");
// {
//     DiamondTrap d1("D1");
//     DiamondTrap d2("D2");

//     small("Burn EP in d1 only");
//     spamAttacks(d1, "tgt", 5);

//     small("d2 should still have fresh EP");
//     for (int i = 0; i < 3; ++i) d2.attack("tgt");
//     std::cout << "If d1 and d2 behave independently, you're not using static for HP/EP/AD.\n";
// }

// banner("06) Edge cases + robustness");
// {
//     DiamondTrap e("Edge");
//     small("Attack with enough times to hit EP 0, then try beRepaired and attack again");
//     spamAttacks(e, "dummy", 60); // go past 50 to show repeated 'no energy' messaging handled
//     e.beRepaired(5);             // probably fails — confirm message
//     e.attack("dummy");           // still fails

//     small("Take huge damage beyond current HP");
//     e.takeDamage(1000);          // should cap at 0 HP, no negative vibes
//     e.attack("dummy");           // cannot attack at 0 HP
//     e.beRepaired(100);           // depending on your rules, usually blocked at 0 HP
// }

// banner("07) Construction chaining visual check (scoped)");
// {
//     std::cout << "Create a nested scope and watch the order\n";
//     {
//         DiamondTrap z("Zeta");
//         z.whoAmI();
//     }
//     std::cout << "Zeta went out of scope. You should see reverse destruction order once per subobject.\n";
// }

// banner("08) Bonus: polymorphic calls through ClapTrap*");
// {
//     small("Even via base pointer, attack() should dispatch ScavTrap::attack (non-virtual in subject? ok, then check message matches Scav's style)");
//     DiamondTrap p("Poly");
//     ClapTrap* base = &p;
//     base->attack("poly-dummy"); // If attack is virtual in your project, this hits ScavTrap’s version.
//                                 // If not virtual, message will look like ClapTrap’s — subject wants ScavTrap::attack to be used,
//                                 // so consider making it virtual or using 'using ScavTrap::attack;' in DiamondTrap.
// }