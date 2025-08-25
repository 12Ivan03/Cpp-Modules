/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:54:39 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/25 16:57:46 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {};

Point::Point(const float x, const float y) : _x(x), _y(y) {};

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY()) {};

Point& Point::operator=(const Point &other) {
	(void)other;
	return *this;
};

Point::~Point() {};

Fixed Point::getX() const {
	return this->_x;
};

Fixed Point::getY() const {
	return this->_y;
};