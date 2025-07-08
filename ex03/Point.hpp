/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-troc <hho-troc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:39:25 by hho-troc          #+#    #+#             */
/*   Updated: 2025/07/08 11:58:49 by hho-troc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    const Fixed _x;
    const Fixed _y;

public:
    Point();                                 // default constructor
    Point(const float x, const float y);     // constructor with floats
    Point(const Point &other);               // copy constructor
    Point &operator=(const Point &other);    // assignment operator
    ~Point();

    Fixed getX() const;
    Fixed getY() const;
};

#endif
