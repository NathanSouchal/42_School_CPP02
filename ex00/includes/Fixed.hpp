/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:21:22 by nsouchal          #+#    #+#             */
/*   Updated: 2024/07/24 09:47:31 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cstring>

class Fixed
{
	private:
	int					value;
	static const int	nb_bits;

	public:
	Fixed(void);
	Fixed(Fixed const & src);
	Fixed &operator=(Fixed const &rhs);
	~Fixed(void);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif