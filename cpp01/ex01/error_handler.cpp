/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:20:29 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/18 11:56:00 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	error_handler(int erNum) {

	if (erNum == 1)
		std::cout << "Error: invalid integer: between 1 and 100 000" << std::endl;
	if (erNum == 2)
		std::cout << "Error: invalid name" << std::endl;
	if (erNum == 3)
		std::cout << "Error: valid format: ./moar_brainz numberOfZombies Name" << std::endl;
}
