#ifndef _WORLD_HPP_
#define _WORLD_HPP_

#include <vector>
#include "vec3.hpp"
#include "object.hpp"
#include "ray.hpp"

class World
{
private:
    // 右手坐标系世界
    point LIGHT;
    // 视口大小,间隔大小
    int WIDTH{400}, HEIGHT{300}, INTERVAL{100};
    // 存放世界中的物体
    std::vector <Object> OBJECTS;
    // 迭代深度
    int MAX{3};
public:
    World() : LIGHT{0, 400, 1000} {};
    // 修改光源位置0
    void setLight(const point &);
    // 设置相机和视口
    void setCamera(const int, const int, const int);
    // 添加物体，目前仅支持球体
    void addObject(const Object &);
    // 修改深度
    void setDepth(const int);
    // 渲染光线追踪
    void render();
    // 计算视口点坐标
    double getCoordinate(const int, const int) const;
    // 计算交点
    point getCross(Ray &) const;
};

#endif