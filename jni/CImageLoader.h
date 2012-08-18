/*
 * Copyright (c) 2012 lailai. All Rights Reserved.
 */

#ifndef _CIMAGELOADER_H_
#define _CIMAGELOADER_H_

#include <iostream>

using namespace std;

/**
 * �摜�t�@�C���ǂݍ��݃N���X�ł��B
 * @author lailai
 */
class CImageLoader
{
public:
    CImageLoader(void);
    CImageLoader(string filePath);
    ~CImageLoader(void);
    void setImage(string filePath);
    void loadImage(void);
    void getImageData(unsigned char *);
    int getWidth(void);
    int getHeight(void);
    int getDepth(void);
private:
    string imageFilePath;
    unsigned char *imageData;
    int imageWidth;
    int imageHeight;
    int imageDepth;
};

#endif
