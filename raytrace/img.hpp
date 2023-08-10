#ifndef _IMG_HPP_
#define _IMG_HPP_

#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdint>
#include "array.hpp"

class Image
{
private:
    std::string PATH{};
    int SIZE[2];
    int *** IMAGE;
    struct BMPHeader {
        uint16_t    signature;
        uint32_t    fileSize;
        uint16_t    reserved1;
        uint16_t    reserved2;
        uint32_t    dataOffset;
        uint32_t    headerSize;
        int32_t     width;
        int32_t     height;
        uint16_t    planes;
        uint16_t    bitsPerPixel;
        uint32_t    compression;
        uint32_t    dataSize;
        int32_t     horizontalResolution;
        int32_t     verticalResolution;
        uint32_t    colors;
        uint32_t    importantColors;
    } HEAD;
public:
    Image() {};
    Image(const int size[2]) : SIZE{size[0], size[1]} { initImage(); initHead(); };

    // 设置信息
    void setFile(const std::string &);
    void setSize(const int, const int);
    void initImage();
    void initHead();
    void readImage(int ***);

    // 写入图像
    void writeBmp();
};

#endif