#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

class Array
{
private:
    int *** ARRAY;
public:
    Array(const int, const int);
    ~Array();

    // 获取数组
    int *** array();

    // 重载访问符
    int ** operator[](int);
};

# endif