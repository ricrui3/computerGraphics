#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int points[1000000];
#define imgWidth 500
#define imgHeight 500
int matrixBuff[imgWidth][imgHeight] = {0};
float Translation2DMatrix[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
float Scaling2DMatrix[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
float Rotation2DMatrix[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
float TrasnformationMatrix[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
int k = 0;
char bgColour[] = "24 116 205 ", lineColour[] = "0 15 255 "; 

void RAWreading(float point[3][4], FILE *RAWwwr);
void SetIdentityAll();
void Translation2D(float TransX, float TransY);
void Scaling2D(float ScaleX, float ScaleY);
void Rotation2D(float rotDeg);
void PrintMatrix();
void MatrixVectMult(float Vector[3][4], float matrix[3][3]);
void Matrix3x3Mult(float matrix[3][3]);
int Point(int x1p, int y1p, int x2p, int y2p);
void SpecialCase(int option,int x1p,int y1p,int x2p,int y2p,float m,float b,int swapOp);
void CalculateM(float *mAux, int x1p, int y1p, int x2p, int y2p);
void CalculateB(float *b, int y1p, float m, int x1p);
void swap(int *punto1, int *punto2);
void DrawTheDamnLine(int NoImg);