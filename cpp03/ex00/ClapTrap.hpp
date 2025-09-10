/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:23:33 by ipavlov           #+#    #+#             */
/*   Updated: 2025/09/10 12:54:57 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	
	private:
		std::string _name {};
		int _health {10};
		int _energy {10};
		int _damage {0};
		
		// Set - Get
		std::string getName() const;
		int getHealth() const;
		int getEnergy() const;
		int getDamage() const;
		void setName(std::string name);
		void setHealth(int points);
		void setEnergy(int energy);
		void setDamage(int damage);

	public:
		ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();
		ClapTrap(std::string name);
		
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	printInfo() const;
		void	printfErrorMsg(const std::string &name) const;
		void	printMessage(const std::string &msg) const;
};

#endif
