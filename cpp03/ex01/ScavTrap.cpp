/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:57:04 by ipavlov           #+#    #+#             */
/*   Updated: 2025/09/10 15:52:38 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap() {
	
	_health = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "ScavTrap default constructor" << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "Copy constructor called from the ScavTrap" << std::endl;
};

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {

	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "Assignment operator called form ScavTrap" << std::endl;
	}
	return *this;
};

ScavTrap::~ScavTrap() {
	std::cout << "Destructor called form ScavTrap" << std::endl;
};

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	
	_health = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "Name passed as argument called form ScavTrap" << std::endl;
};

void	ScavTrap::attack(const std::string &target) {

	if (!getHealth())
		return printfErrorMsg(_name + "'s Health is 0. Canot attack", "ScavTrap ");
	if (!getEnergy())
		return printfErrorMsg(_name + "'s energy is 0. Canot attack", "ScavTrap ");
	setEnergy(getEnergy() - 1);
	
	printMessage(_name + " attacks " + target + ", causing " + std::to_string(_damage) + " points of damage!", "ScavTrap ");
};

void	ScavTrap::gateKeeper() {
	std::cout << "ScavTrap is now in a Gate Keeper mode" << std::endl;
};
