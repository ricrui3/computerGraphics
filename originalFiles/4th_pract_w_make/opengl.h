#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef struct mvstack{
	int ModelVM[16];
} MVSTACK;

typedef struct projstack{
	int ProjM[16];
} PROJSTACK;

typedef struct textstack{
	int TextM[16];
} TEXTSTACK;

int ObjectCoord[1000][4] = {0};
int normDevV[1000][3] = {0};
int pointCount, aux;
#define imgWidth 1000
#define imgHeight 1000
#define GL_LINES "GL_LINES"
#define TEXTURE "TEXTURE"
#define MODELVIEW "MODELVIEW"
#define PROJECTION "PROJECTION"

MVSTACK modVstack[100];
PROJSTACK prjcStack[100];
TEXTSTACK texStack[100];
int mvflag = 0, projflag = 0, textflag = 0;
int MVStCount = 0, PROJCount = 0, TEXTCount = 0;

float GLn = 0.0, GLf = 1.0;
int GLx, GLy , GLw = imgWidth, GLh = imgHeight;
int GLox = imgWidth / 2, GLoy = imgHeight / 2, GLpx = imgWidth, GLpy = imgHeight; 

int matrixBuff[imgWidth][imgHeight] = {0};
char bgColour[] = "24 116 205 ", lineColour[] = "255 255 255 ";
int *pointer;
int eyeCoord[4];
int vertexClipCoord[4];
int vertexNormalized[3];

void glBegin(char name[]);
void glVertex2ui(int x, int y);
void glEnd();
void glDepthRange(float n, float f);
void glViewPort(int x, int y, int w, int h);
void glMatrixMode(char name[]);
void glLoadMatrix(int matrix[]);
void glLoadMatrixd(double matrix[]);
void glMultMatrixd(double matrix[]);
void glLoadIdentity();
void glRotated(double ang, double x, double y, double z);
void glTranslated(double x, double y, double z);
void glScaled(double x, double y, double z);
void glFrustum(double l, double r, double b, double t, double n, double f );
void glOrtho(double l, double r, double b, double t, double n, double f);
void glPushMatrix();
void glPopMatrix();
double Norm(double v[]);
void CreateImage();
void SetLines(int x0, int y0, int x1, int y1);
void MakeIdentity(int original[16]);
void FinalViewportTransformation(int p1);
void MatrixMult(int Vector[], int matrix[16]);