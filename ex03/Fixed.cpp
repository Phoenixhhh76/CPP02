/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-troc <hho-troc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:39:25 by hho-troc          #+#    #+#             */
/*   Updated: 2025/07/08 12:01:41 by hho-troc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Default constructor
Fixed::Fixed() : _fixedPointValue(0) {
    // std::cout << "Default constructor called" << std::endl;
}

// Int constructor
Fixed::Fixed(const int n) {
    // std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = n << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float f) {
    // std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(f * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &other) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _fixedPointValue = other.getRawBits();
    return *this;
}

// Destructor
Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

// Getter
int Fixed::getRawBits(void) const {
    return _fixedPointValue;
}

// Setter
void Fixed::setRawBits(int const raw) {
    _fixedPointValue = raw;
}

// Convert to float
float Fixed::toFloat(void) const {
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

// Convert to int
int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    return Fixed(this->toFloat() / rhs.toFloat());
}

// Comparison operators
bool Fixed::operator>(const Fixed &rhs) const {
    return _fixedPointValue > rhs._fixedPointValue;
}

bool Fixed::operator<(const Fixed &rhs) const {
    return _fixedPointValue < rhs._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return _fixedPointValue >= rhs._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return _fixedPointValue <= rhs._fixedPointValue;
}

bool Fixed::operator==(const Fixed &rhs) const {
    return _fixedPointValue == rhs._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &rhs) const {
    return _fixedPointValue != rhs._fixedPointValue;
}

// Pre-increment
Fixed &Fixed::operator++() {
    ++_fixedPointValue;
    return *this;
}

// Post-increment
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++_fixedPointValue;
    return temp;
}

// Pre-decrement
Fixed &Fixed::operator--() {
    --_fixedPointValue;
    return *this;
}

// Post-decrement
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --_fixedPointValue;
    return temp;
}

// Min / Max
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

// Stream output
std::ostream &operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat();
    return out;
}

