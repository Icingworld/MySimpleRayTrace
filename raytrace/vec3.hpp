#ifndef _VEC3_HPP_
#define _VEC3_HPP_

#include <cmath>

class vec3
{
private:
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

#endif