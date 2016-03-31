#include "stdio.h"
#include "stdlib.h"

int points[1000];
int pointCount, aux;
#define imgWidth 1000
#define imgHeight 1000
int matrixBuff[imgWidth][imgHeight] = {0};
char bgColour[] = "24 116 205 ", lineColour[] = "255 255 255 "; 

void glBegin(char name[]);
void glVertex2ui(int x, int y);
void glEnd();
void CreateImage();
void SetLines(int x0, int y0, int x1, int y1);