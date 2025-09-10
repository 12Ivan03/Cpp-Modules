/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:56:58 by ipavlov           #+#    #+#             */
/*   Updated: 2025/09/10 13:31:56 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

	public:
		FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap();

		FragTrap(const std::string name);

		void	attack(const std::string &target);
		void	highFivesGuys(void) const;

		static const int defaultHealth {100};
		static const int defaultEnergy {100};
		static const int defaultDamage {30};
};

#endif