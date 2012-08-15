/*
 * Copyright (c) 2012 lailai All Rights Reserved.
 */

package net.lailai.android.mmd.mikumikuplayer;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView.Renderer;

/**
 * OpenGL ES�̕`��N���X�ł��B
 * @author lailai
 */
public class MMPRenderer implements Renderer {

    static {
        System.loadLibrary("mmp");
    }

    /**
     * �`��p�N���X�̃C���X�^���X�𐶐����܂��B
     */
    public MMPRenderer() {
        // nothing to do
    }

    /**
     * NDK�Ńt���[����`�悵�܂��B
     */
    public native static void NDKonDrawFrame();

    /**
     * NDK��Surface�ύX���̐ݒ�����܂��B
     * @param width ��ʕ�
     * @param height ��ʍ���
     */
    public native static void NDKonSurfaceChanged(int width, int height);

    /**
     * NDK��Surface�쐬���������{���܂��B
     */
    public native static void NDKonSurfaceCreated();

    /* (�� Javadoc)
     * @see android.opengl.GLSurfaceView.Renderer#onDrawFrame(javax.microedition.khronos.opengles.GL10)
     */
    public void onDrawFrame(GL10 arg0) {
        NDKonDrawFrame();
    }

    /* (�� Javadoc)
     * @see android.opengl.GLSurfaceView.Renderer#onSurfaceChanged(javax.microedition.khronos.opengles.GL10, int, int)
     */
    public void onSurfaceChanged(GL10 arg0, int arg1, int arg2) {
        NDKonSurfaceChanged(arg1, arg2);
    }

    /* (�� Javadoc)
     * @see android.opengl.GLSurfaceView.Renderer#onSurfaceCreated(javax.microedition.khronos.opengles.GL10, javax.microedition.khronos.egl.EGLConfig)
     */
    public void onSurfaceCreated(GL10 arg0, EGLConfig arg1) {
        NDKonSurfaceCreated();
    }

}
