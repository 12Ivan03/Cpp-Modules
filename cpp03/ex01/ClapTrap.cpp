/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:56:58 by ipavlov           #+#    #+#             */
/*   Updated: 2025/09/10 16:05:10 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

// --~~--~~--~~--~~--~~ OCcF ~~--~~--~~--~~--~~--//

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap ctor" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &other) : 
	_name(other._name),
	_health(other._health),
	_damage(other._damage),
	_energy(other._energy) {
	
	std::cout << "ClapTrap copy ctor" << std::endl;

};

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	
	std::cout << "ClapTrap copy operator ctor" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_health = other._health;
		this->_damage = other._damage;
		this->_energy = other._energy;
	}
	return *this;
};

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap dtor" << std::endl;
};

ClapTrap::ClapTrap(std::string name) : _name(name) {
	std::cout << "ClapTrap ctor name" << std::endl;
};


// --~~--~~--~~--~~--~~ Action ~~--~~--~~--~~--~~--//

void	ClapTrap::attack(const std::string &target) {

	if (!getHealth())
		return printfErrorMsg(_name + "'s Health is 0. Canot attack", "ClapTrap ");
	if (!getEnergy())
		return printfErrorMsg(_name + "'s Energy is 0. Canot attack", "ClapTrap ");
	setEnergy(getEnergy() - 1);
	
	printMessage(_name + " attacks " + target + ", causing " + std::to_string(_damage) + " points of damage!", "ClapTrap ");
	
};

void	ClapTrap::takeDamage(unsigned int amount) {
	
	if (getHealth() == 0)
		return printMessage(_name + " is already dead!", "ClapTrap ");
	
	if (getHealth() < amount) {
		setHealth(0);
		return printMessage(_name + " took " + std::to_string(amount) + " demage and he/she is dead!", "ClapTrap ");
	}
	else
		setHealth(getHealth() - amount);
	
	printMessage(_name + " has taken " + std::to_string(amount) + " damage on his health", "ClapTrap ");
};

void	ClapTrap::beRepaired(unsigned int amount) {
	
	if (!getEnergy())
		return printfErrorMsg(_name + "'s Energy is 0. Canot repair", "ClapTrap ");
	else if (!getHealth())
		return printfErrorMsg(_name + "'s Health is 0 you're already dead!", "ClapTrap ");
	
	setHealth(getHealth() + amount);
	setEnergy(getEnergy() - 1);
	printMessage(_name + " regained " + std::to_string(amount) + " amount of energy.", "ClapTrap ");
	
};



// --~~--~~--~~--~~--~~ Set - Get ~~--~~--~~--~~--~~--//

std::string ClapTrap::getName() const {
	return this->_name;
};

int ClapTrap::getHealth() const {
	return this->_health;
};

int ClapTrap::getEnergy() const {
	return this->_energy;
};
		
int ClapTrap::getDamage() const {
	return this->_damage;
};

void ClapTrap::setName(std::string name) {
	this->_name = name;
};

void ClapTrap::setHealth(int health) {
	this->_health = health;
};

void ClapTrap::setEnergy(int energy) {
	this->_energy = energy;
};

void ClapTrap::setDamage(int damage) {
	this->_damage = damage;
};


// --~~--~~--~~--~~--~~ Print Messages ~~--~~--~~--~~--~~--//

void	ClapTrap::printfErrorMsg(const std::string &name, const std::string &clapTrapType) const {
	std::cout << clapTrapType << name << std::endl;
	printInfo();
};

void	ClapTrap::printMessage(const std::string &msg, const std::string &clapTrapType) const {
	std::cout << clapTrapType << msg << std::endl;
	printInfo();
}


// --~~--~~--~~--~~--~~ Print Info ~~--~~--~~--~~--~~--//


void	ClapTrap::printInfo() const {
	std::cout << std::endl;
	std::cout << "\t" << "\t"<< "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "--~~--~~- General  Info -~~--~~--" << std::endl;
	std::cout << "\t" << "\t"<< "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "| Health:	| " << this->_health << "		|" << std::endl;
	std::cout << "\t" << "\t"<< "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "| Energy:	| " << this->_energy << "		|" << std::endl;
	std::cout << "\t" << "\t"<< "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "| Damage:	| " << this->_damage << "		|" << std::endl;
	std::cout << "\t" << "\t"<< "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "--~~--~~--~~--~~--~~--~~--~~--~~-" << std::endl;
	std::cout << std::endl;
};