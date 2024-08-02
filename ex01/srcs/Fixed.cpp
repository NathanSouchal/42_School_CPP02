/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:31:33 by nsouchal          #+#    #+#             */
/*   Updated: 2024/07/25 10:15:11 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::nb_bits = 8;

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = nb << this->nb_bits;
	return ;
}

Fixed::Fixed(float const nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(nb*(1<<this->nb_bits));
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = rhs.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value  = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->value) / static_cast<float>(1 << this->nb_bits));
}

int		Fixed::toInt(void) const
{
	return (this->value >> this->nb_bits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}