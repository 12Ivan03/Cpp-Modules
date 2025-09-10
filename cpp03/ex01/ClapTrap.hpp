/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:57:00 by ipavlov           #+#    #+#             */
/*   Updated: 2025/09/10 13:04:31 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

	protected:
		std::string _name;
		int _health {10};
		int _energy {10};
		int _damage {0};
		
		std::string getName() const;
		int getHealth() const;
		int getEnergy() const;
		int getDamage() const;
		void setName(std::string name);
		void setHealth(int health);
		void setEnergy(int energy);
		void setDamage(int damage);

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap&other);
		~ClapTrap();

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	printInfo() const;
		void	printfErrorMsg(const std::string &name, const std::string &clapTrapType) const;
		void	printMessage(const std::string &msg, const std::string &target) const;
};

#endif