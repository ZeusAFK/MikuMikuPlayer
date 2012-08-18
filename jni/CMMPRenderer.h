/*
 * Copyright (c) 2012 lailai. All Rights Reserved.
 */

#ifndef _CMMPRENDERER_H_
#define _CMMPRENDERER_H_

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <iostream>

using namespace std;

enum {
    UNIFORM_PROJ_MAT,
    UNIFORM_TEXTURE,
    NUM_UNIFORMS
};

/**
 * MikuMikuPlayer�̕`��N���X�ł��B
 * @author lailai
 */
class CMMPRenderer
{
public:
    CMMPRenderer(void);
    ~CMMPRenderer(void);
    void init(void);
    void render(void);
    GLuint loadShader(string shaderCode, GLuint shaderType);
    GLuint loadProgram(GLuint hVertexShader, GLuint hFragmentShader);
private:
    string vertexShader;
    string fragmentShader;
    GLuint hProgram;
    GLuint hVbo;
    GLuint hIbo;
    GLuint hTexture;
    GLuint uniforms[NUM_UNIFORMS];
};

#endif