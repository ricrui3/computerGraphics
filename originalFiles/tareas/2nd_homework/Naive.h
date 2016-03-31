#include "stdio.h"
#include "stdlib.h"

int points[1000];
#define imgWidth 1000
#define imgHeight 1000
int matrixBuff[imgWidth][imgHeight] = {0};
char bgColour[] = "24 116 205 ", lineColour[] = "0 15 255 "; 

void swap(int *punto1, int *punto2);
int NaiveA(int x1p ,int y1p, int x2p, int y2p);
void CalculateM(float *mAux, int x1p, int y1p, int x2p, int y2p);
void CalculateB(float *b, int y1p, float m, int x1p);
void SpecialCase(int option,int x1p,int y1p,int x2p,int y2p,float m,float b,int swapOp);
void DrawTheDamnLine();