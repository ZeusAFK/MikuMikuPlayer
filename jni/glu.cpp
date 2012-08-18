#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <math.h>
#include "glu.h"

//-------------------------------------------------------------------
// �֐���: gluLookAt
// ����: ���_��ݒ肷��
//     �\�[�X��NDK�̃T���v�����p�N����
// ����:eyex    : ���_��x���W
//     eyey    : ���_��y���W
//     eyez    : ���_��z���W
//     centerx : �펋�_��x���W
//     centery : �펋�_��y���W
//     centerz : �펋�_��z���W
//     upx     : ���E�̏�ƂȂ������x����
//     upy     : ���E�̏�ƂȂ������y����
//     upz     : ���E�̏�ƂȂ������z����
//     m       : ���_�v�Z���ʂ��o��
// �߂�l: �Ȃ�
//-------------------------------------------------------------------
void gluLookAt(GLfloat eyex, GLfloat eyey, GLfloat eyez,
			   GLfloat centerx, GLfloat centery, GLfloat centerz,
			   GLfloat upx, GLfloat upy, GLfloat upz,
			   GLfloat *m)
{
	GLfloat w[3];
	GLfloat x[3];
	GLfloat y[3];
	GLfloat z[3];
	GLfloat length;

	// z(at - eye)
	z[0] = centerx - eyex;
	z[1] = centery - eyey;
	z[2] = centerz - eyez;
//	z[0] = eyex - centerx;
//	z[1] = eyey - centery;
//	z[2] = eyez - centerz;
	length = sqrt(z[0] * z[0] + z[1] * z[1] + z[2] * z[2]);
	z[0] = z[0] / length;
	z[1] = z[1] / length;
	z[2] = z[2] / length;

	// x(up cross z)
	x[0] = upy * z[2] - upz * z[1];
	x[1] = -upx * z[2] + upz * z[0];
	x[2] = upx * z[1] - upy * z[0];
	length = sqrt(x[0] * x[0] + x[1] * x[1] + x[2] * x[2]);
	x[0] = x[0] / length;
	x[1] = x[1] / length;
	x[2] = x[2] / length;

	// y(z cross x)
	y[0] = z[1] * x[2] - z[2] * x[1];
	y[1] = -z[0] * x[2] + z[2] * x[0];
	y[2] = z[0] * x[1] - z[1] * x[0];

	// w[0](x dot eye)
	// w[1](y dot eye)
	// w[2](z dot eye)
	w[0] = x[0] * eyex + x[1] * eyey + x[2] * eyez;
	w[1] = y[0] * eyex + y[1] * eyey + y[2] * eyez;
	w[2] = z[0] * eyex + z[1] * eyey + z[2] * eyez;

	m[0] = x[0]; m[1] = y[0]; m[2] = z[0]; m[3] = 0.0f;
	m[4] = x[1]; m[5] = y[1]; m[6] = z[1]; m[7] = 0.0f;
	m[8] = x[2]; m[9] = y[2]; m[10] = z[2]; m[11] = 0.0f;
	m[12] = -w[0]; m[13] = -w[1]; m[14] = -w[2]; m[15] = 1.0f;
}

//-------------------------------------------------------------------
// �֐���: gluPerspective
// ����: ���E��ݒ肷��
//     �\�[�X��NDK�̃T���v�����p�N����
// ����:fovy   : ����p(�x)
//     aspect : �A�X�y�N�g��(��/����)
//     zNear  : ���_����ł��߂��_�܂ł̋���
//     zFar   : ���_����ł������_�܂ł̋���
//     m      : ���E�v�Z���ʂ��o��
// �߂�l: �Ȃ�
//-------------------------------------------------------------------
void gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar, GLfloat *m)
{
	GLfloat radian = 2 * fovy * 3.14159265f / 360;
	GLfloat ys = 1 / tan(radian / 2);
	GLfloat xs = ys / aspect;

	GLfloat w22 = zFar / (zFar - zNear);
	GLfloat w32 = -zNear * zFar / (zFar - zNear);

	m[0] = xs; m[1] = 0.0f; m[2] = 0.0f; m[3] = 0.0f;
	m[4] = 0.0f; m[5] = ys; m[6] = 0.0f; m[7] = 0.0f;
	m[8] = 0.0f; m[9] = 0.0f; m[10] = w22; m[11] = 1.0f;
	m[12] = 0.0f; m[13] = 0.0f; m[14] = w32; m[15] = 0.0f;
}
