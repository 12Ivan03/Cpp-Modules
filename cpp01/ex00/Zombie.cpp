/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:43:34 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/18 10:58:33 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : m_name(name) {}

Zombie::~Zombie() {
    std::cout << this->m_name << " is destroyed." << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
