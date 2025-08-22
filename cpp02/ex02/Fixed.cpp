/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:31:28 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/22 17:47:34 by ipavlov          ###   ########.fr       */
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
		result._value = this->_value + other._value;

		return result;
	};

	Fixed Fixed::operator-(const Fixed &other) const {
		
		Fixed result;
		result._value = this->_value - other._value;
		
		return result;
	};


	/* 
		Va X Vb = (A-real X 2^f)(B-real X 2^f) = (A-real X B-real) X 2^2f 
		== Va X Vb / _fractionBits
	*/ 
	Fixed Fixed::operator*(const Fixed &other) const {
		
		long long	classValue = static_cast<long long>(this->_value);
		long long	theOtherValue = static_cast<long long>(other._value); 
		long long	numResult;
		Fixed		result;

		numResult = classValue * theOtherValue;
		result._value = static_cast<int>(numResult >> _fractionalBits);
		
		return result;
	};

	/*
		((A x 2^f) << f ) / (B x 2^f)
		= (A x 2^f x 2^f) / (B x 2^f)
		= (A/B) x 2^f
	*/
	Fixed Fixed::operator/(const Fixed &other) const {
		
		long long	classValue = static_cast<long long>(this->_value);
		long long	theOtherValue = static_cast<long long>(other._value);
		long long	resultValue;
		Fixed		result;

		if (theOtherValue == 0)
			return result;

		resultValue = (classValue << _fractionalBits) / theOtherValue;
		result._value = static_cast<int>(resultValue);
		
		return result;
	};


// ~~--~~--~~ print overload ~~--~~--~~//
	
	std::ostream& operator<<(std::ostream &oStream, const Fixed &fp) {
		return oStream << fp.toFloat();	
	};