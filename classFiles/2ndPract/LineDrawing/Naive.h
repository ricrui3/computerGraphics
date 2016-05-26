#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int point1[1000][2];
int PoinPos = 0, MaxX, MinX, MaxY, Min;
#define imgWidth 2000
#define imgHeight 2000
int matrixBuff[imgWidth][imgHeight] = {0};

float Translation2DMatrix[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
float Scaling2DMatrix[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
float Rotation2DMatrix[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
float TrasnformationMatrix[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

float Translation3DMatrix[4][4] = {
    {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
float Scaling3DMatrix[4][4] = {
    {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
float Rotation3DxMatrix[4][4] = {
    {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
float Rotation3DyMatrix[4][4] = {
    {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
float Rotation3DzMatrix[4][4] = {
    {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
float TrasnfMatrix3D[4][4] = {
    {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

float ProjMatrix[4][4] = {
    {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

int k = 0;
char bgColour[] = "255 255 255 ", lineColour[] = "0 0 0 ";
//char bgColour[] = "24 116 205 ", lineColour[] = "0 15 255 ";

void RAWreading(float point[3][4], FILE *RAWwwr);
void SetIdentityAll();
void Translation2D(float TransX, float TransY);
void Scaling2D(float ScaleX, float ScaleY);
void Rotation2D(float rotDeg);
void MatrixVectMult(float Vector[3][4], float matrix[3][3]);
void Matrix3x3Mult(float matrix[3][3]);
void Translation3D(float TransX, float TransY, float TransZ);
void Scaling3D(float ScaleX, float ScaleY, float ScaleZ);
void Rotation3Dx(float rotDeg);
void Rotation3Dy(float rotDeg);
void Rotation3Dz(float rotDeg);
void MatrixVectMult4x4(float Vector[3][4], float matrix[4][4]);
void Matrix4x4Mult(float matrix[4][4]);
void PrintMatrix(int option);
int Point(int x1p, int y1p, int x2p, int y2p);
void SpecialCase(int option, int x1p, int y1p, int x2p, int y2p, float m,
                 float b, int swapOp);
void CalculateM(float *mAux, int x1p, int y1p, int x2p, int y2p);
void CalculateB(float *b, int y1p, float m, int x1p);
void swap(int *punto1, int *punto2);
void DrawTheDamnLine(int NoImg);
