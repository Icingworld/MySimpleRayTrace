#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_

#include "vec3.hpp"

enum Material { GLASS, ROUGH };

class Object
{
private:
    point CENTER;
    double RADIUS;
    int MATERIAL;
public:
    Object(point & center, double radius, int material) : CENTER(center), RADIUS(radius), MATERIAL(material) {};
    point center() const;
    double radius() const;
    int material() const;
};

#endif