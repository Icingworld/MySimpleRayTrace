#include "vec3.hpp"
#include "ray.hpp"
#include "img.hpp"
#include "array.hpp"
#include <iostream>

int main()
{
    int size[2]{400, 300};
    Image image(size);
    color test(213, 166, 189);
    Array img(size[0], size[1]);
    // 设置像素
    for (int i = 0; i < size[0]; i++) {
        for (int j = 0; j < size[1]; j++) {
            img[i][j] = test.toIntVec();
        }
    }
    std::clog << "Get All Pixel !\n" << std::flush;
    image.setFile("test.bmp");
    image.readImage(img.array());
    image.writeBmp();
    std::clog << "Done !\n" << std::flush;
    return 0;
}