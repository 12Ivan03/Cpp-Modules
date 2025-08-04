/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:47:00 by ipavlov           #+#    #+#             */
/*   Updated: 2025/07/31 17:47:11 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// *** // Helper functions for the finctions bellow // *** //

long long	checkNumber(long long num) {
	
	if (num <= 0 || num > INT_MAX)
		return -1;
	return (num);
}

int	getNumber(std::string argvOne) {
	
	long long num;

	std::stringstream ss(argvOne);
	if (ss >> num && ss.eof())
		if (checkNumber(num) == -1)
			return (-1);
	return (int)num;
}

bool checkName(std::string name) {
	
	int start = name.find_first_not_of(WHITE_SPACE);
	if (start == std::string::npos) {
		name.clear();
		return false;
	}
	int end = name.find_last_not_of(WHITE_SPACE);
	name = name.substr(start, end - start + 1);
	if (name.empty())
		return false;

	return true;
}

// *** // Functions called from main.cpp to validate arguments // *** //

bool	evalArguments(int &N, std::string &name, char *argv[]) {
			
		N = getNumber(argv[1]);
		if (N == -1)
			return (error_handler(1), false);

		name = argv[2];
		if (!checkName(name))
			return (error_handler(2), false);
		
		return true;
}

void	announceZombies(Zombie* newZombies, int N) {

	for (int i = 0; i < N; i++) {
		std::cout << "Zombie " << i + 1 << " : " ;
		newZombies[i].announce();
	}
}
