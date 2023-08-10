#ifndef _RAY_HPP_
#define _RAY_HPP_

#include "vec3.hpp"

class Ray
{
private:
    // 原点和方向
    point ORIGIN{};
    vec3 DIRECTION{};
public:
    // 初始化射线
    Ray() : ORIGIN(), DIRECTION() {};
    Ray(const point & points, const vec3 & vec) : ORIGIN(points), DIRECTION(vec) {};

    // 获取原点和方向
    point origin() const;
    vec3 direction() const;

    // 获取当前点
    point at(const double) const;
};

#endif