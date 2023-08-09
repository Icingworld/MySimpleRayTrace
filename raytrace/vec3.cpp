#include "vec3.hpp"

double vec3::x() const
{
    return vec[0];
}

double vec3::y() const
{
    return vec[1];
}

double vec3::z() const
{
    return vec[2];
}

double vec3::modulo() const
{
    double sum = vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2];
    return sqrt(sum);
}

vec3 & vec3::operator+=(vec3 & m)
{
    vec[0] += m.vec[0];
    vec[1] += m.vec[1];
    vec[2] += m.vec[2];
    return * this;
}

vec3 & vec3::operator-=(vec3 & m)
{
    vec[0] -= m.vec[0];
    vec[1] -= m.vec[1];
    vec[2] -= m.vec[2];
    return * this;
}

vec3 & vec3::operator*=(double k)
{
    vec[0] *= k;
    vec[1] *= k;
    vec[2] *= k;
    return * this;
}

vec3 & vec3::operator/=(double k)
{
    return * this *= 1 / k;
}

vec3 & vec3::operator-()
{
    vec[0] = -vec[0];
    vec[1] = -vec[1];
    vec[2] = -vec[2];
    return * this;
}

// vec3 vec3::operator-()
// {
//     return vec3(-vec[0], -vec[1], -vec[2]);
// }

double vec3::operator[](int i) const
{
    return vec[i];
}

double & vec3::operator[](int i)
{
    return vec[i];
}

bool vec3::operator==(vec3 & m) const
{
    if (vec[0] == m.vec[0] && vec[1] == m.vec[1] && vec[2] == m.vec[2])
        return true;
    return false;
}