

#include "glut.h"


class CPt2D
{
public:
	float x, y;
};
#define numVerts 8
CPt2D verts[20] =
{
	{100.0, -30.0},
	{-100.0, 30.0},
	{0.0, 50.0},
	{400,0},
	{350,250},
	{-350,-250},
	{20, 350},
	{-60, -150}
};

const int winLeftBitCode = 0x1;
const int winRightBitCode = 0x2;
const int winBottomBitCode = 0x4;
const int winTopBitCode = 0x8;

//ȫΪ0����ʾ���ڲ�
int pointInside(int code)
{
	return int(!code);
}

//����Ϊ1����ȫ�����ڲ�
int lineOutside(int code1, int code2)
{
	return int(code1 & code2);
}

//��ȫ���ڲ�
int lineInside(int code1, int code2)
{
	return int(!(code1 | code2));
}

unsigned char encode(CPt2D pt, CPt2D winMin, CPt2D winMax)
{
	unsigned char code = 0x00;

	//��������


	return code;
}

void swapPts(CPt2D *p1, CPt2D *p2)
{
	CPt2D tmp;
	//��������


}

void swapCodes(unsigned char *c1, unsigned char *c2)
{
	unsigned char tmp;
	//��������


}

void lineClipCohSuth(CPt2D winMin, CPt2D winMax, CPt2D p1, CPt2D p2)
{
	unsigned char code1, code2;
	int done = false;
	int plotLine = false;
	float k = 0;

	while (!done)
	{
		code1 = encode(p1, winMin, winMax);
		code2 = encode(p2, winMin, winMax);

		//��������



		done = true;

	}

	if (plotLine)
	{
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2f(p1.x, p1.y);
		glVertex2f(p2.x, p2.y);
		glEnd();
	}

}

void InitGL(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-400, 400, -300, 300);

	glMatrixMode(GL_MODELVIEW);

}

void RenderRect(int width, int height)
{
	glColor3f(0.0, 0.0, 1.0);

	glBegin(GL_LINE_LOOP);
	glVertex2f(-width / 2, -height / 2);
	glVertex2f(-width / 2, height / 2);
	glVertex2f(width / 2, height / 2);
	glVertex2f(width / 2, -height / 2);
	glEnd();
}

void RenderLine(CPt2D *verts)
{
	int i = 0;

	while (i < numVerts)
	{
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_LINES);
		glVertex2f(verts[i].x, verts[i].y);
		glVertex2f(verts[i + 1].x, verts[i + 1].y);
		glEnd();

		i += 2;
	}
}

void RenderTriangle(CPt2D *verts)
{
	GLint k;
	glBegin(GL_TRIANGLES);
	for (k = 0; k < 3; k++)
	{
		glVertex2f(verts[k].x, verts[k].y);
	}
	glEnd();
}

void RenderScene()
{
	int width = 400;
	int height = 400;
	CPt2D winMin = { -width / 2, -height / 2 };
	CPt2D winMax = { width / 2, height / 2 };

	glClear(GL_COLOR_BUFFER_BIT);

	RenderRect(width, height);

	RenderLine(verts);

	int i = 0;
	while (i < numVerts)
	{
		lineClipCohSuth(winMin, winMax, verts[i], verts[i + 1]);
		i += 2;
	}


	glFlush();
}

void main(int argc, char ** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Clip Coh Suth Example");

	InitGL();
	glutDisplayFunc(RenderScene);

	glutMainLoop();
}




