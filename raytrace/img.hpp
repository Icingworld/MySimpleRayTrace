#ifndef _IMG_HPP_
#define _IMG_HPP_

#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdint>
#include "array.hpp"

// 设置1字节对齐，防止写入文件时2字节类型默认被4字节对齐
#pragma pack(push, 1)

// 位图文件头14字节
typedef struct tagBITMAPFILEHEADER {
	uint16_t bfType;			// 文件类型
	uint32_t bfSize;			// 文件大小
	uint16_t bfReserved1;		// 保留字
	uint16_t bfReserved2;		// 保留字
	uint32_t bfOffBits;		    // 文件头到实际图像数据之间的偏移量共54字节
} BITMAPFILEHEADER;

// 位图信息头40字节
typedef struct tagBITMAPINFOHEADER {
	uint32_t biSize;			// 位图信息头大小
	uint32_t biWidth;			// 位图宽度
	uint32_t biHeight;			// 位图高度
	uint16_t biPlanes;			// 颜色平面数
	uint16_t biBitCount;		// 每个像素的位数
	uint32_t biCompression;	    // 压缩方式
	uint32_t biSizeImage;	    // 位图全部像素占用的字节数
	uint32_t biXPelsPerMeter;   // 水平方向分辨率
	uint32_t biYPelsPerMeter;   // 垂直方向分辨率
	uint32_t biClrUsed;		    // 使用的颜色数
	uint32_t biClrImportant;   	// 重要颜色数
} BITMAPINFOHEADER;

// 调色板
typedef struct tagRGBQUAD {
	uint8_t rgbBlue;
	uint8_t rgbGreen;
	uint8_t rgbRed;
	uint8_t rgbReserved;
} RGBQUAD;

// 位图数据
typedef struct tagIMAGEDATA {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} IMAGEDATA;


class Image
{
private:
    std::string PATH{};
    int SIZE[2];
    int *** IMAGE;
    BITMAPFILEHEADER FILEHEAD;
    BITMAPINFOHEADER INFOHEAD;
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