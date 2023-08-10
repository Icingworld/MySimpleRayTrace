#ifndef _VEC3_HPP_
#define _VEC3_HPP_

#include <cmath>

class vec3
{
public:
    // 一个int类型的3维数组
    double vec[3]{};
public:
    // 初始化数组
    vec3() : vec{0, 0, 0} {};
    vec3(double NUM1, double NUM2, double NUM3) : vec{NUM1, NUM2, NUM3} {};
    ~vec3() {};

    //获取3维
    double x() const;
    double y() const;
    double z() const;

    // 获取3维数组的模
    double modulo() const;

    // 重载运算符
    vec3 & operator+=(vec3 &);
    vec3 & operator-=(vec3 &);
    vec3 & operator*=(double);
    vec3 & operator/=(double);
    vec3 & operator-();
    double operator[](int) const;
    double & operator[](int);
    bool operator==(vec3 &) const;
};

// 将三维点、RGB颜色定义为vec3类型
using point = vec3;
using color = vec3;

// 与向量相关的内联函数

inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.vec[0] << ' ' << v.vec[1] << ' ' << v.vec[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.vec[0] + v.vec[0], u.vec[1] + v.vec[1], u.vec[2] + v.vec[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.vec[0] - v.vec[0], u.vec[1] - v.vec[1], u.vec[2] - v.vec[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.vec[0] * v.vec[0], u.vec[1] * v.vec[1], u.vec[2] * v.vec[2]);
}

inline vec3 operator*(double t, const vec3 &v) {
    return vec3(t*v.vec[0], t*v.vec[1], t*v.vec[2]);
}

inline vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

inline vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

#endif