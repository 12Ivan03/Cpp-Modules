/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:56:58 by ipavlov           #+#    #+#             */
/*   Updated: 2025/09/10 16:28:36 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_health = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "Constructor -> FragTrap" << std::endl;
};

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "Copy Constructor -> FragTrap" << std::endl;
};


FragTrap& FragTrap::operator=(const FragTrap &other) {
	
	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "Assignment operator -> FragTrap" << std::endl;
	}
	return *this;
};

FragTrap::~FragTrap() {
	std::cout << "Destructor -> FragTrap" << std::endl;
};

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	_health = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "Name constructor -> FragTrap" << std::endl;
};

void	FragTrap::highFivesGuys(void) const {
	std::cout << "Displays positive high-fives request on the standard output." << std::endl;
};

void	FragTrap::attack(const std::string &target) {
	
	if (!getHealth())
		return printfErrorMsg("FragTrap ", _name + "'s health is 0. Cannot attack");
	if (!getEnergy())
		return printfErrorMsg("FragTrap ", _name + "'s Energy is 0. Cannot attack");
	setEnergy(getEnergy() - 1);
	
	printMessage("FragTrap ", _name + " attacks " + target + ", causing " + std::to_string(_damage) + " points of damage!");
};
