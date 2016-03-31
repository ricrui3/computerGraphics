#include "stdio.h"
#include "stdlib.h"

int ObjectCoord[1000][4] = {0};
int normDevV[1000][3] = {0};
int pointCount, aux;
#define imgWidth 1000
#define imgHeight 1000
#define GL_LINES "GL_LINES"
float GLn = 0.0, GLf = 1.0;
int GLx, GLy , GLw = imgWidth, GLh = imgHeight;
int GLox = imgWidth / 2, GLoy = imgHeight / 2, GLpx = imgWidth, GLpy = imgHeight; 

int matrixBuff[imgWidth][imgHeight] = {0};
char bgColour[] = "24 116 205 ", lineColour[] = "255 255 255 ";

int ModelVM[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
int ProjM[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
int eyeCoord[4];
int vertexClipCoord[4];
int vertexNormalized[3];

void glBegin(char name[]);
void glVertex2ui(int x, int y);
void glEnd();
void glDepthRange(float n, float f);
void glViewPort(int x, int y, int w, int h);
void CreateImage();
void SetLines(int x0, int y0, int x1, int y1);
void MakeIdentity(int original[4][4]);
void FinalViewportTransformation(int p1);
void MatrixMult(int Vector[], int matrix[4][4]);