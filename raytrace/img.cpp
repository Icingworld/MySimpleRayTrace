#include "img.hpp"

void Image::setFile(const std::string & path)
{
    PATH = path;
}

void Image::setSize(const int width, const int height)
{
    SIZE[0] = width;
    SIZE[1] = height;
    initImage();
}

void Image::initImage()
{
    // 初始化图像2维数组
    Array array(SIZE[0], SIZE[1]);
    IMAGE = array.array();
}

void Image::readImage(int *** data)
{
    for (int i = 0; i < SIZE[0]; i++) {
        for (int j = 0; j < SIZE[1]; j++) {
            IMAGE[i][j] = data[i][j];
        }
    }
}

void Image::initHead()
{
    HEAD.signature = 0x4D42; // "BM"
    HEAD.fileSize = sizeof(BMPHeader) + SIZE[0] * SIZE[1] * 3; // 3 bytes per pixel for 24-bit color
    HEAD.reserved1 = 0;
    HEAD.reserved2 = 0;
    HEAD.dataOffset = sizeof(BMPHeader);
    HEAD.headerSize = 40;
    HEAD.width = SIZE[0];
    HEAD.height = SIZE[1];
    HEAD.planes = 1;
    HEAD.bitsPerPixel = 24;
    HEAD.compression = 0;
    HEAD.dataSize = SIZE[0] * SIZE[1] * 3;
    HEAD.horizontalResolution = 2835; // 72 dpi
    HEAD.verticalResolution = 2835; // 72 dpi
    HEAD.colors = 0;
    HEAD.importantColors = 0;
}

void Image::writeBmp()
{
    std::ofstream bmpFile(PATH, std::ios::binary);
    if (!bmpFile) {
        std::cout << "Error opening file for writing!" << std::endl;
        return;
    }
    bmpFile.write(reinterpret_cast<char*>(&HEAD), sizeof(BMPHeader));
    bmpFile.write(reinterpret_cast<char*>(IMAGE), SIZE[0] * SIZE[1] * 3);
    bmpFile.close();
}