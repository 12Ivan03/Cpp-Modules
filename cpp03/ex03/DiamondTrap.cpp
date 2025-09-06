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

// --~~--~~--~~--~~--~~ OCcF ~~--~~--~~--~~--~~--//


DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	_health = 100;
	_energy = 50;
	_damage = 30;
	std::cout << "DiamondTrap default constructor" << std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
	std::cout << "Copy Destructor -> DiamondTrap" << std::endl;
};

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {

	if (this != &other) {
		ClapTrap::operator=(other);
		_name = other._name;
		std::cout << "Assign constructor -> DiamondTrap" << std::endl;
	}
	return *this;
};

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_scav_name"), FragTrap(name + "_frag_name"), _name(name)
{
	_health = 100;
	_energy = 50;
	_damage = 30;
	std::cout << "DiamondTrap name constructor" << std::endl;
};

DiamondTrap::~DiamondTrap() {
	std::cout << "Distructor -> DiamondTrap" << std::endl;

};

// --~~--~~--~~--~~--~~ Action ~~--~~--~~--~~--~~--//


void	DiamondTrap::whoAmI() {
	std::cout << "Hello said, " << this->_name << ". Hello answered " << ClapTrap::_name << std::endl;
};