#include "vec3.hpp"
#include "img.hpp"
#include <iostream>

int main()
{
    vec3 point(1, 2, 3);
    std::cout << point.x() << point.y() << point.z() << std::endl;
    std::cout << point.modulo() << std::endl;
    point *= 3;
    std::cout << point.x() << point.y() << point.z() << std::endl;
    std::cout << point.modulo() << std::endl;
    -point;
    std::cout << point.x() << point.y() << point.z() << std::endl;
    std::cout << point.modulo() << std::endl;
    return 0;
}