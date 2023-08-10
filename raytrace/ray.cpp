#include "ray.hpp"

point Ray::origin() const
{
    return ORIGIN;
}

vec3 Ray::direction() const
{
    return DIRECTION;
}

point Ray::at(const double t) const
{
    // 获得t位置点
    return ORIGIN + t * DIRECTION;
}