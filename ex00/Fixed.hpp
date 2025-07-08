/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-troc <hho-troc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:37:37 by hho-troc          #+#    #+#             */
/*   Updated: 2025/07/08 11:37:40 by hho-troc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int _fixedPointValue;                     // Internal fixed-point storage
    static const int _fractionalBits = 8;     // Always 8 fractional bits

public:
    Fixed();                                  // Default constructor
    Fixed(const Fixed &other);                // Copy constructor
    Fixed &operator=(const Fixed &other);     // Assignment operator
    ~Fixed();                                 // Destructor

    int getRawBits(void) const;               // Getter
    void setRawBits(int const raw);           // Setter
};

#endif
