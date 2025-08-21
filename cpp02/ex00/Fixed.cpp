/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Foxed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:14:05 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/19 18:14:06 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &other) {

	std::cout << "Copy constructor called" << std::endl;
	this->_value = other._value;
};

Fixed& Fixed::operator=(const Fixed &other) {

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_value = other.getRawBits();
	}
	return *this;
};

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

int		Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member functions called" << std::endl;
	return this->_value;
};

void	Fixed::setRawBits( int const value ) {
	
	std::cout << "setRawBits member functions called" << std::endl;
	this->_value = value;
};

// int		Fixed::getFractionalBits() { 
// 	return _fractionalBits; 
// };