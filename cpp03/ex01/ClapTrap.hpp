/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:57:00 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/29 13:57:35 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

	private:
		std::string _name;
		int _helath {10};
		int _energy {10};
		int _damage {0};
		
		std::string getName() const;
		int getHealth() const;
		int getEnergy() const;
		int getDamae() const;
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

		void	attak(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

};

#endif