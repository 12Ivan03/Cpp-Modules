/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:14:09 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/26 11:39:33 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// ~~--~~--~~--~~--~~--~~ OCCF ~~--~~--~~--~~--~~--~~ //

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &other) {

	std::cout << "Copy constructor called" << std::endl;
	this->_value = other.getRawBits();
};

Fixed& Fixed::operator=(const Fixed &other) {
	
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
};

Fixed::~Fixed() {

	std::cout << "Destructor called" << std::endl;
};

// ~~--~~--``` Good practice ```--~~--~~//

int		Fixed::getRawBits( void ) const {
	return _value;
};

void	Fixed::setRawBits(const int value) {
	this->_value = value;
};

// ~~--~~--~~--~~--~~--~~ Int ~~--~~--~~--~~--~~--~~ //

Fixed::Fixed(const int valueI) {

	std::cout << "Int constructor called" << std::endl;
	_value = valueI << _fractionalBits;
	
};

int		Fixed::toInt( void ) const {
	
	return _value >> _fractionalBits;
};

// ~~--~~--~~--~~--~~--~~ Float ~~--~~--~~--~~--~~--~~ //

Fixed::Fixed(float value) {

	std::cout << "Float constructor called" << std::endl;
	this->_value = static_cast<int>(roundf(value * (1 << _fractionalBits)));
};


float	Fixed::toFloat( void ) const {
	
	return static_cast<float>(_value) / (1 << _fractionalBits);
};

/* 
	Calculating the delta and error (epsilon) for float to Fixed conversion:
	1 << _fractionalBits = 256 ; // 2^8 
	1 << _fractionalBits = 2^8 = 256 ;
	
		2(8) = 256 ;
		1/256 = delta = 0.00390625 ;
		error <= delta / 2 ;
*/

// ~~--~~--~~--~~--~~ Overload operator ~~--~~--~~--~~--~~ //

std::ostream& operator<<(std::ostream &oStream, const Fixed &fx) {
	return oStream << fx.toFloat();
};
