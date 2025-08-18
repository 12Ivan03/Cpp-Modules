/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:43:18 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/18 16:47:56 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {

    Zombie* heapZombie = newZombie("Harper");
    heapZombie->announce();
    
    delete heapZombie;
    heapZombie = nullptr;

    randomChump("Steven");

    return 0;
}
