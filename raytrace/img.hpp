#ifndef _IMG_HPP_
#define _IMG_HPP_

#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdint>
#include "array.hpp"

// 位图文件头
typedef struct tagBITMAPFILEHEADER {
	uint16_t bfType;			//文件类型
	uint32_t bfSize;			//文件大小
	uint16_t bfReserved1;		//保留字
	uint16_t bfReserved2;		//保留字
	uint32_t bfOffBits;		    //文件头到实际图像数据之间的偏移量
}BITMAPFILEHEADER;

// 位图信息头
typedef struct tagBITMAPINFOHEADER {
	DWORD biSize;			    //位图信息头大小
	LONG biWidth;			    //位图宽度
	LONG biHeight;			    //位图高度
	WORD biPlanes;			    //颜色平面数
	WORD biBitCount;		    //每个像素的位数
	DWORD biCompression;	    //压缩方式
	DWORD biSizeImage;	    	//位图全部像素占用的字节数
	LONG biXPelsPerMeter;   	//水平方向分辨率
	LONG biYPelsPerMeter;   	//垂直方向分辨率
	DWORD biClrUsed;		    //使用的颜色数
	DWORD biClrImportant;   	//重要颜色数
}BITMAPINFOHEADER;

// 调色板
typedef struct tagRGBQUAD {
	BYTE rgbBlue;
	BYTE rgbGreen;
	BYTE rgbRed;
	BYTE rgbReserved;
}RGBQUAD;

// 位图数据
typedef struct tagIMAGEDATA {
	BYTE red;
	BYTE green;
	BYTE blue;
}IMAGEDATA;


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