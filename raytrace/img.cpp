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
    // 初始化位图文件头
    FILEHEAD.bfType =  0x4D42;
    FILEHEAD.bfSize = sizeof(BITMAPFILEHEADER) * SIZE[0] * SIZE[1] * 3;
    FILEHEAD.bfReserved1 = 0;
    FILEHEAD.bfReserved2 = 0;
    FILEHEAD.bfOffBits = 54;
    // 初始化位图信息头
    INFOHEAD.biSize = 40;
    INFOHEAD.biWidth = SIZE[0];
    INFOHEAD.biHeight = SIZE[1];
    INFOHEAD.biPlanes = 1;
    INFOHEAD.biBitCount = 24;
    INFOHEAD.biCompression = 0;
    INFOHEAD.biSizeImage = SIZE[0] * SIZE[1] * 3;
    INFOHEAD.biXPelsPerMeter = 2834;
    INFOHEAD.biYPelsPerMeter = 2834;
    INFOHEAD.biClrUsed = 0;
    INFOHEAD.biClrImportant = 0;
}

void Image::writeBmp()
{
    std::ofstream bmpFile(PATH, std::ios::binary);
    if (!bmpFile) {
        std::cout << "Error opening file for writing!" << std::endl;
        return;
    }
    // bmpFile.write(reinterpret_cast<char *>(&FILEHEAD), sizeof(FILEHEAD));
    // bmpFile.write(reinterpret_cast<char *>(&INFOHEAD), sizeof(INFOHEAD));
    bmpFile.write((char *)(&FILEHEAD), sizeof(FILEHEAD));
    bmpFile.write((char *)(&INFOHEAD), sizeof(INFOHEAD));
    uint8_t * imageData = new uint8_t[3];
    for (int i = 0; i < SIZE[0]; i++) {
        for (int j = 0; j < SIZE[1]; j++) {
            imageData[0] = static_cast<uint8_t>(IMAGE[i][j][0]);
            imageData[1] = static_cast<uint8_t>(IMAGE[i][j][1]);
            imageData[2] = static_cast<uint8_t>(IMAGE[i][j][2]);
            bmpFile.write((char *)(imageData), 3);
        }
    }
    bmpFile.close();
}