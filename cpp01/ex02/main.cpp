/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:16:04 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/18 11:56:39 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {

    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << std::endl << "The memory address of a string on the stack:     " << &str << std::endl;
    std::cout << "The memory address of a pointer:                 " << stringPTR << std::endl;
    std::cout << "The memory address of a reference:               " << &stringREF << std::endl << std::endl;

    std::cout << "The value of a string on the stack:          " << str << std::endl;
    std::cout << "The value of a pointer:                      "  << *stringPTR << std::endl;
    std::cout << "The value of a reference:                    "  << stringREF << std::endl << std::endl;

    return 0;
}