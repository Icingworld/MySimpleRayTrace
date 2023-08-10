#include "ray.hpp"

point ray::origin() const
{
    return ORIGIN;
}

vec3 ray::direction() const
{
    return DIRECTION;
}

point ray::at(const double t) const
{
    // 获得t位置点
    return ORIGIN + t * DIRECTION;
}