/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:14:09 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/19 18:14:10 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

	private: 
		int 				_value;
		static const int	_fractionalBits;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		Fixed(const int value);
		Fixed(const float value);

		int		getRawBits( void ) const;
		void	setRawBits(const int value);

		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream &oStream, const Fixed &fx);

#endif