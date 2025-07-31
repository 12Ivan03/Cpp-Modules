/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:43:49 by ipavlov           #+#    #+#             */
/*   Updated: 2025/07/31 16:11:45 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CPP
#define ZOMBIE_CPP

#include <iostream>

class   Zombie {
    private:
        std::string m_name {};

    public:
        Zombie(std::string name);
        ~Zombie();
        
        void announce( void );
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif
