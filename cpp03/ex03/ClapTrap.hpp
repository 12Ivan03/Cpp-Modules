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

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

	protected:
		std::string _name;
		int _health {10};
		int _energy {10};
		int _damage {0};

		void		setName(std::string name);
		void		setHealth(int health);
		void		setEnergy(int energy);
		void		setDamage(int damage);
		std::string	getName() const;
		int			getHealth() const;
		int			getEnergy() const;
		int			getDamage() const;

	public:
		ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();
		ClapTrap(const std::string name);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	printInfo() const;
		void	printfErrorMsg(const std::string &subject, const std::string &name) const;
		void	printMessage(const std::string &subject, const std::string &msg) const;
	
};

#endif