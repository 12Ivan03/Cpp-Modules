/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 18:14:08 by ipavlov           #+#    #+#             */
/*   Updated: 2025/08/26 11:25:59 by ipavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED__HPP
#define FIXED__HPP

#include <iostream>

class Fixed {

	private:
		int					_value;
		static const int	_fractionalBits;

    public:
		Fixed();
		Fixed(const Fixed &other); // copy constructor
		Fixed &operator=(const Fixed &other); // assignment operatior overload
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const value );
};

#endif