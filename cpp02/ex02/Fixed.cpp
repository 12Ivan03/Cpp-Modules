/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:31:28 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/25 15:14:35 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

	const int Fixed::_fractionalBits = 8;

// ~~--~~--~~--~~--~~ OCCF ~~--~~--~~--~~--~~--~~//
	
	Fixed::Fixed() : _value(0) {};
	
	Fixed::Fixed(const Fixed &other) {
		this->_value = other.getBits();
	};
	
	Fixed& Fixed::operator=(const Fixed &other) {
		
		if (this != &other)
			this->_value = other.getBits();
		return *this;
	};
	
	Fixed::~Fixed() {};
	
// ~~--~~--~~ get, set ~~--~~--~~//
	
	int 	Fixed::getBits(void) const {
		return this->_value;
	};
	
	void	Fixed::setBits(const int value) {
		this->_value = value;
	};
	
// ~~--~~--~~ int, float ~~--~~--~~//
	
	Fixed::Fixed(const int value) {
		_value = value << _fractionalBits;
	};
	
	int	Fixed::toInt(void) const {
		return _value >> _fractionalBits;
	}
	
	Fixed::Fixed(const float value) {
		this->_value = static_cast<int>(roundf(value * (1 << _fractionalBits)));
	};

	float Fixed::toFloat(void) const {
		return static_cast<float>(_value) / (1 << _fractionalBits);
	};

	
// ~~--~~--~~ comparison operators ~~--~~--~~//

	bool	Fixed::operator>(const Fixed &other) const {
		
		if (this->_value > other._value)
			return true;
		return false;
	};

	bool	Fixed::operator<(const Fixed &other) const {
		
		if (this->_value < other._value)
			return true;
		return false;
	};
	
	bool	Fixed::operator>=(const Fixed &other) const {
		
		if (this->_value >= other._value)
			return true;
		return false;
	};


	bool	Fixed::operator<=(const Fixed &other) const {
		
		if (this->_value <= other._value)
			return true;
		return false;
	};
	
	bool	Fixed::operator==(const Fixed &other) const{
		
		if (this->_value == other._value)
			return true;
		return false;
	};
	
	bool	Fixed::operator!=(const Fixed &other) const{
		
		if (this->_value != other._value)
			return true;
		return false;
	};

// ~~--~~--~~ arithmetic operations ~~--~~--~~//

	Fixed Fixed::operator+(const Fixed &other) const {
		
		Fixed result;
		result.setBits(this->_value + other._value);

		return result;
	};

	Fixed Fixed::operator-(const Fixed &other) const {
		
		Fixed result;
		result.setBits(this->_value - other._value);
		
		return result;
	};
	
	Fixed Fixed::operator*(const Fixed &other) const {
		
		long long	thisValue = static_cast<long long>(this->_value);
		long long	otherValue = static_cast<long long>(other._value); 
		long long	numResult;
		Fixed		result;

		numResult = thisValue * otherValue;
		result.setBits(static_cast<int>(numResult >> _fractionalBits));
		
		return result;
	};

	Fixed Fixed::operator/(const Fixed &other) const {
		
		long long	thisValue = static_cast<long long>(this->_value);
		long long	otherValue = static_cast<long long>(other._value);
		long long	resultValue;
		Fixed		result;

		if (otherValue == 0)
			return result;

		resultValue = (thisValue << _fractionalBits) / otherValue;
		result.setBits(static_cast<int>(resultValue));

		return result;
	};

	// Pre ++a & --a; 

	Fixed& Fixed::operator++() {
		
		this->_value += 1;
		return *this;	
	};

	Fixed& Fixed::operator--() {
		
		this->_value -= 1;
		return *this;
	};

	// Post a++ & a--

	Fixed Fixed::operator++(int) {
		
		Fixed cpyValue(*this);
		++this->_value;
		return cpyValue;
	};

	Fixed Fixed::operator--(int) {

		Fixed cpyValue(*this);
		--this->_value;
		return cpyValue;
	};

	// Min 
	
	Fixed& Fixed::min(Fixed &a, Fixed &b) {
		
		if (a._value > b._value)
			return b;
		return a;
	};

	const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
		
		if (a._value > b._value)
			return b;
		return a;
	};

	// Max

	Fixed& Fixed::max(Fixed &a, Fixed &b) {
		
		if (a._value < b._value)
			return b;
		return a;
	};

	const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
		
		if (a._value < b._value)
			return b;
		return a;
	};


// ~~--~~--~~ print overload ~~--~~--~~//
	
	std::ostream& operator<<(std::ostream &oStream, const Fixed &fp) {
		return oStream << fp.toFloat();	
	};