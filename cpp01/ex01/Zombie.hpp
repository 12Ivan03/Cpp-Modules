/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:16:15 by ipavlov           #+#    #+#             */
/*   Updated: 2025/07/31 16:49:55 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CPP
#define ZOMBIE_CPP

#include <iostream>
#include <sstream>
#include <string>
#include <limits.h>

# define WHITE_SPACE " \t\n\r\f\v"

class Zombie {

	private: 
		std::string z_name {};
		
	public:
		Zombie();
		~Zombie();
		
		void setName(std::string name);
		std::string getName() const;
		void announce();
};

void	error_handler(int);
bool	evalArguments(int &N, std::string &name, char *argv[]);
Zombie* zombieHorde(int N, std::string name);
void	announceZombies(Zombie* newZombies, int N);

#endif