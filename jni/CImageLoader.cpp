/*
 * Copyright (c) 2012 lailai. All Rights Reserved.
 */

#include <iostream>

#include "CImageLoader.h"
#include "bitmap24.h"

using namespace std;

/**
 * �R���X�g���N�^<br />
 * ��̃C���X�^���X�𐶐����܂��B
 */
CImageLoader::CImageLoader(void)
{
    imageData = NULL;
    imageWidth = 0;
    imageHeight = 0;
    imageDepth = 0;
    string filePath("");
    setImage(filePath);
}

/**
 * �R���X�g���N�^<br />
 * �摜�t�@�C���p�X���������C���X�^���X�𐶐����܂��B
 */
CImageLoader::CImageLoader(string filePath)
{
    imageData = NULL;
    imageWidth = 0;
    imageHeight = 0;
    imageDepth = 0;
    setImage(filePath);
}

/**
 * �f�X�g���N�^<br />
 */
CImageLoader::~CImageLoader(void)
{
    if (imageData != NULL) {
        delete [] imageData;
        imageData = NULL;
    }
}

/**
 * �摜�t�@�C���p�X��ݒ肵�܂��B
 * @param filePath �摜�t�@�C���p�X
 */
void CImageLoader::setImage(string filePath)
{
    imageFilePath = filePath;
}

/**
 * �摜�t�@�C����ǂݍ��݂܂��B
 */
void CImageLoader::loadImage(void)
{
    string::size_type offset = imageFilePath.rfind(".bmp");
    if (offset == string::npos) {
        offset = imageFilePath.rfind(".BMP");
    }
    if (offset == string::npos) {
        return;
    }
    if (imageFilePath.substr(offset) == string(".bmp") || imageFilePath.substr(offset) == string(".BMP")) {
        CBitmap24 *bitmap = new CBitmap24();
        bitmap->Load(imageFilePath);
        imageWidth = bitmap->GetWidth();
        imageHeight = bitmap->GetHeight();
        imageDepth = 24;
        unsigned char *tmp = reinterpret_cast<unsigned char *>(bitmap->GetPixelAddress(0, 0));
        imageData = new unsigned char[imageWidth * imageHeight * (imageDepth / 8)];
        for (int i = 0; i < imageWidth * imageHeight * (imageDepth / 8); i++) {
            imageData[i] = tmp[i];
        }
    }
}

/**
 * �摜�f�[�^���擾���܂��B
 * @param imageDataBuffer �\�߃��������m�ۂ����o�b�t�@
 */
void CImageLoader::getImageData(unsigned char *imageDataBuffer)
{
    for (int i = 0; i < imageWidth * imageHeight * (imageDepth / 8); i++) {
        imageDataBuffer[i] = imageData[i];
    }
}

/**
 * �摜�̉������擾���܂��B
 * @return �摜�̉���
 */
int CImageLoader::getWidth(void)
{
    return imageWidth;
}

/**
 * �摜�̍������擾���܂��B
 * @return �摜�̍���
 */
int CImageLoader::getHeight(void)
{
    return imageHeight;
}

/**
 * �摜�̐[�����擾���܂��B
 * @return �摜�̐[��
 */
int CImageLoader::getDepth(void)
{
    return imageDepth;
}
