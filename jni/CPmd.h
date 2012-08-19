/**
 * Copyright (c) 2012 lailai. All Rights Reserved.
 */

#ifndef _CPMD_H_
#define _CPMD_H_

/**
 * �w�b�_���\����
 */
typedef struct tagPmdHeader {
    char szMagic[4];	// PMD���Ƃ��Ă̓T�C�Y3�����A�I�[�L�����Ȃ��̂ŃT�C�Y4�Ƃ���
    float fVersion;
    char szModelName[20];
    char szComment[256];
} PMDHEADER;

/**
 * ���_���\����
 */
typedef struct tagPmdVertex {
    float fPosition[3];
    float fNormalVector[3];
    float fUv[2];
    unsigned short wBoneNumber[2];
    unsigned char byBoneWeight;
    unsigned char byEdgeFlag;
} PMDVERTEX;

/**
 * �ގ����\����
 */
typedef struct tagPmdMaterial {
    float fDiffuseColor[3];
    float fAlpha;
    float fSpecularity;
    float fSpecularColor[3];
    float fMirrorColor[3];
    unsigned char byToonIndex;
    unsigned char byEdgeFlag;
    unsigned long dwFaceNumber;
    char szTextureFileName[21];	// PMD���Ƃ��Ă̓T�C�Y20�����A�I�[�L�����Ȃ��ꍇ������̂ŃT�C�Y21�Ƃ���
    char szTextureFileName1[21];	// �e�N�X�`���t�@�C���ƃX�t�B�A�t�@�C���ɕ����邽�߂̃o�b�t�@
    char szTextureFileName2[21];
    unsigned int uiTexId;
} PMDMATERIAL;

/**
 * �{�[�����\����
 */
typedef struct tagPmdBone {
    char szBoneName[20];
    unsigned short wParentBoneIndex;
    unsigned short wTailBoneIndex;
    unsigned char byBoneType;
    unsigned short wIKBoneIndex;
    float fBoneHeadPos[3];
    float fQuaternion[4];
} PMDBONE;

/**
 * PMD�����܂Ƃ߂��N���X
 */
class CPmd
{
public:
    char *mszFilePath;
    char *mszDirPath;
    PMDHEADER mHeader;
    unsigned long mdwVertexCount;
    PMDVERTEX *mlpVertex;
    unsigned long mdwFaceCount;
    unsigned short *mlpwFaceIndex;
    unsigned long mdwMaterialCount;
    PMDMATERIAL *mlpMaterial;
    unsigned short mwBoneCount;
    PMDBONE *mlpBone;

    CPmd(void);
    virtual ~CPmd(void);
    int load(char *szFileName);
    void free(void);
};

#endif
