/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-troc <hho-troc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:39:25 by hho-troc          #+#    #+#             */
/*   Updated: 2025/07/08 11:59:26 by hho-troc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    Point inside(5.0f, 5.0f);
    Point outside(10.0f, 10.0f);
    Point onEdge(5.0f, 0.0f);

    std::cout << "inside: " << (bsp(a, b, c, inside) ? "YES" : "NO") << std::endl;
    std::cout << "outside: " << (bsp(a, b, c, outside) ? "YES" : "NO") << std::endl;
    std::cout << "on edge: " << (bsp(a, b, c, onEdge) ? "YES" : "NO") << std::endl;

    return 0;
}
