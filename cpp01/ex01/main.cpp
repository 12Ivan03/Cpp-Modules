/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:46:00 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/18 11:15:10 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int argc, char **argv) {

	int N = 0;
	std::string name {};
	Zombie* newZombies {};

	if (argc != 3) {
		error_handler(3);
		return 1;
	}
	if (evalArguments(N ,name, argv))
	{
		newZombies = zombieHorde(N, name);
		announceZombies(newZombies, N);
		delete[] newZombies;
	} else
		return 1;

	return 0;
}
