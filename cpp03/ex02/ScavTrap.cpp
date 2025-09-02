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

ScavTrap::ScavTrap() : ClapTrap() {
	_health = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "Default initializer. -> ScavTrap" << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "Copy constructor -> ScavTrap" << std::endl;
};

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {

	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "Assignment operator -> ScavTrap" << std::endl;
	}
	return *this;
};

ScavTrap::~ScavTrap() {
	std::cout << "Destructor -> ScavTrap" << std::endl;
};

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	_health = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "Name constructor -> ScavTrap" << std::endl;
};

void	ScavTrap::attack(const std::string &target) {

	if (!getEnergy())
		return printfErrorMsg(_name + "'s energy is 0", "ScavTrap ");
	setEnergy(getEnergy() - 1);
	
	printMessage("ScavTrap ", _name + " attacks " + target + ", causing " + std::to_string(_damage) + " points of damage!");
};

void	ScavTrap::gateKeeper() {
	std::cout << "ScavTrap is now in a Gate keeper mode" << std::endl;
};
