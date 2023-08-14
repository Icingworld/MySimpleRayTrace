#include "world.hpp"

void World::setLight(const point & newLight)
{
    LIGHT.modify(newLight);
}

void World::setCamera(const int width, const int heigth, const int interval)
{
    WIDTH = width;
    HEIGHT = heigth;
    INTERVAL = interval;
}

void World::addObject(const Object & newObject)
{
    OBJECTS.push_back(newObject);
}

void World::setDepth(const int depth)
{
    MAX = depth;
}

void World::render()
{
    point raw;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // 计算视口上该点坐标
            // 这里有笛卡尔坐标系问题,需查询bmp格式
            point viewPoint = {getCoordinate(i, WIDTH), getCoordinate(j, HEIGHT), INTERVAL};
            // 获得射线
            Ray ray(raw, viewPoint/viewPoint.modulo());
            // 计算和球体的交点
            // 先判断距离,再计算交点
        }
    }
}

double World::getCoordinate(const int i, const int all) const
{
    if (static_cast<int>((static_cast<double>(all) / 2.0)) * 2 == all)
    {
        // 是偶数
        return static_cast<double>(i) + 0.5 - static_cast<double>(all) / 2.0;
    } else {
        // 是奇数
        return static_cast<double>(i) - (static_cast<double>(all - 1)) / 2.0;
    }
}

point World::getCross(Ray &) const
{

}