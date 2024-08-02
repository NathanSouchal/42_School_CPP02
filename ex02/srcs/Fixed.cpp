/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:31:33 by nsouchal          #+#    #+#             */
/*   Updated: 2024/07/25 08:55:34 by nsouchal         ###   ########.fr       */
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
	return ((float)this->value / (float)(1 << this->nb_bits));
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


/*--------------------------Arithmetic operator-----------------------------*/


Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}


/*--------------------------Compare operator-----------------------------*/


bool	Fixed::operator<(Fixed const &rhs) const
{
	if (this->value < rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	if (this->value > rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	if (this->value <= rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	if (this->value >= rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	if (this->value == rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	if (this->value != rhs.getRawBits())
		return (true);
	else
		return (false);
}


/*--------------------------Incre/Decre operator-----------------------------*/


Fixed	&Fixed::operator++(void)
{
	++this->value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	this->value++;
	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	--this->value;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	this->value--;
	return (temp);
}


/*--------------------------max/min operator-----------------------------*/

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
