/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-troc <hho-troc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:39:25 by hho-troc          #+#    #+#             */
/*   Updated: 2025/07/08 11:59:16 by hho-troc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// 計算三角形面積（使用向量叉積公式）
static Fixed area(const Point &a, const Point &b, const Point &c) {
    Fixed result = (a.getX() * (b.getY() - c.getY()) +
                    b.getX() * (c.getY() - a.getY()) +
                    c.getX() * (a.getY() - b.getY())) / 2;
    return result < 0 ? result * -1 : result;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed total = area(a, b, c);
    Fixed area1 = area(point, b, c);
    Fixed area2 = area(a, point, c);
    Fixed area3 = area(a, b, point);

    // 如果任一小面積為 0（表示在邊上），回傳 false
    if (area1 == 0 || area2 == 0 || area3 == 0)
        return false;

    return total == (area1 + area2 + area3);
}
