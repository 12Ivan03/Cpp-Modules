/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:16:08 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/18 11:07:31 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie::~Zombie() {
	std::cout << "   Zombie " << getName() << " is destrpyed!" << std::endl;
}

void	Zombie::announce() {
	std::cout << getName() << std::endl;
}

void	Zombie::setName(std::string name) {
	this->z_name = name;
}

std::string Zombie::getName() const {
	return z_name;
}
