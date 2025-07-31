/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:20:29 by ipavlov           #+#    #+#             */
/*   Updated: 2025/07/31 17:43:31 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	error_handler(int erNum) {
	if (erNum == 1)
		std::cout << "invalid integer: between 1 and 100 000" << std::endl;
	if (erNum == 2)
		std::cout << "invalid name" << std::endl;
	if (erNum == 3)
		std::cout << "Currect format: ./moar_brainz numberOfZombies Name" << std::endl;
}
