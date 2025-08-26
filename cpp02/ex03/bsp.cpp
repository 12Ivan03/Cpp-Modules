/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:54:36 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/26 10:38:22 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// (a._x * (b._y - c._y) + b._x * (c._y - a._y) + c._x * (a._y - b._y) ) / 2 

Fixed squareOfTriangle( Point const &a, Point const &b, Point const &c) {
	
	Fixed aa = a.getX() * (b.getY() - c.getY());
	Fixed bb = b.getX() * (c.getY() - a.getY());
	Fixed cc = c.getX() * (a.getY() - b.getY());
	Fixed all = aa + bb + cc;

	if (all < Fixed(0))
		return all * -1;
	
	return all;
}

//squareOfTriangle(a , b , point) + squareOfTriangle(a , c , point) + squareOfTriangle(b, c , p oint)

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	
	Fixed sABPoint = squareOfTriangle(a , b , point);
	Fixed sACPoint = squareOfTriangle(a , c , point);
	Fixed sBCPoint = squareOfTriangle(b, c , point);
	Fixed sTriangle = squareOfTriangle(a , b , c);
	Fixed alllABSPoint = sABPoint + sACPoint + sBCPoint;
	
	if (sABPoint == 0 || sACPoint == 0 || sBCPoint == 0)
		return false;

	if (alllABSPoint == sTriangle)
		return true;
	
	return false;
};