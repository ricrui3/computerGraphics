#include "stdio.h"
#include "stdlib.h"
#include "string.h"
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
void print4x4M();

MVSTACK modVstack[100];
PROJSTACK prjcStack[100];
TEXTSTACK texStack[100];
int mvflag = 0, projflag = 0, textflag = 0;
int MVStCount = 0, PROJCount = 0, TEXTCount = 0;
int *pointer;

#define TEXTURE "TEXTURE"
#define MODELVIEW "MODELVIEW"
#define PROJECTION "PROJECTION"

int main()
{
	double matrix[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	double matrix2[16] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
	glMatrixMode(MODELVIEW);
	glLoadMatrixd(matrix);
	print4x4M();
	glPushMatrix();
	glMultMatrixd(matrix2);
	print4x4M();
	glMatrixMode(PROJECTION);
	glLoadMatrixd(matrix2);
	print4x4M();
	glPushMatrix();
	glLoadIdentity();
	print4x4M();
	glMatrixMode(MODELVIEW);
	print4x4M();
	glPopMatrix();
	print4x4M();
	return 0;
}

void glMatrixMode(char name[]){
	if(name == "TEXTURE"){
		pointer = texStack[TEXTCount].TextM;
		textflag = 1;
		mvflag = 0;
		projflag = 0;

	}
	else if (name == "MODELVIEW")
	{
		pointer = modVstack[MVStCount].ModelVM;
		textflag = 0;
		mvflag = 1;
		projflag = 0;
	}
	else if (name == "PROJECTION")
	{
		pointer = prjcStack[PROJCount].ProjM;
		textflag = 0;
		mvflag = 0;
		projflag = 1;
	}
}

void glLoadMatrix(int matrix[]){
	int i;
	for (i = 0; i < 16; i++){
		pointer[i] = matrix[i];
	}
}

void glLoadMatrixd(double matrix[]){
	int i;
	for (i = 0; i < 16; i++){
		pointer[i] = matrix[i];
	}
}

void glMultMatrixd(double matrix[16]){
	int i, j = 0, k = 0, kaux,l;
	int auxMatrix[16] = {0};

	for (i = 0; i < 16; ++i)
	{
		auxMatrix[i] = pointer[i];
	}

	for (i = 0; i < 16; ++i){
		pointer[i] = 0;
		kaux = k;
		for (l = 0; l < 4; l++){
			pointer[i] += auxMatrix[j] * (int)matrix[k];
			//printf("%d %d %d %d\n", i,j,k, kaux);
			//getchar();
			if(k + 1 == kaux + 4)
				k = kaux;
			else 
				k++;
			if(j + 4 > 15)
				j -= 11;
			else
				j+=4;
		}
		///getchar();
		//printf("pointer[%d] = %d\n", i, pointer[i]);
		if((i+1)%4 == 0){
			kaux += 4;
			k = kaux;
			j = 0;
		}
	}
	// c[0] = a[0]*b[0] + a[4]*b[1] + a[8]*b[2] + a[12][3]
	// c[1] = a[1]*b[0] + a[5]*b[1] + a[9]*b[2] + a[13][3]
	// c[2] = a[2]*b[0] + a[6]*b[1] + a[10]*b[2] + a[14][3]
	// c[3] = a[3]*b[0] + a[7]*b[1] + a[11]*b[2] + a[15][3]

	// c[4] = a[0]*b[4] + a[4]*b[5] + a[8]*b[6] + a[12][7]
	// c[5] = a[1]*b[4] + a[5]*b[5] + a[9]*b[6] + a[13][7]
	// c[6] = a[2]*b[4] + a[6]*b[5] + a[10]*b[6] + a[14][7]
	// c[7] = a[3]*b[4] + a[7]*b[5] + a[11]*b[6] + a[15][7]

	// c[8] = a[0]*b[8] + a[4]*b[9] + a[8]*b[10] + a[12][11]
	// c[9] = a[1]*b[8] + a[5]*b[9] + a[9]*b[10] + a[13][11]
	// c[10] = a[2]*b[8] + a[6]*b[9] + a[10]*b[10] + a[14][11]
	// c[11] = a[3]*b[8] + a[7]*b[9] + a[11]*b[10] + a[15][11]

	// c[12] = a[0]*b[12] + a[4]*b[13] + a[8]*b[14] + a[12][15]
	// c[13] = a[1]*b[12] + a[5]*b[13] + a[9]*b[14] + a[13][15]
	// c[14] = a[2]*b[12] + a[6]*b[13] + a[10]*b[14] + a[14][15]
	// c[15] = a[3]*b[12] + a[7]*b[13] + a[11]*b[14] + a[15][15]
}

void glLoadIdentity(){
	double iMatrix[16] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
	glLoadMatrixd(iMatrix);
}

void glRotated(double ang, double x, double y, double z){
	int i, j;
	double v[3] = {x, y, z}; //v = [x,y,z]
	double u[3] = {0};
	double NormOfV;
	double uxut = 0;
	double red = 0.5;
	double angIuxut[9] = {0};
	double R[9] = {0};
	int Id[9] = {1,0,0,0,1,0,0,0,1};

	NormOfV = Norm(v);

	for (i = 0; i < 3; ++i){
		u[i] = v[i] / NormOfV;  // u = v / norm(v)
	}

	double S[9] = {0, u[2], -u[1], -u[2], 0, u[0], u[1], -u[0], 0};
	// S = {0, z', -y', -z', 0, x', y', -x', 0}

	// R = u * ut + cos(ang) * (i - u * ut) + sin(ang) * s----------
	for (i = 0; i < 3; i++){
		uxut += u[i] * u[i];
	}

	for (i = 0; i < 9; i++){
		angIuxut[i] = cos(ang) * (Id[i] - uxut);
	}
	for (i = 0; i < 9; i++){
		R[i] = (uxut + angIuxut[i] + (sin(ang) * S[i]));
		R[i] += red;			
	}
	//---------------------------------------------------------------


	double FM[16] = {R[0], R[1], R[2], 0, R[3], R[4], R[5], 0, R[6], R[7], R[8], 0, 0, 0, 0 ,1};
	printf("\n");
	glMultMatrixd(FM);
}

void glTranslated(double x, double y, double z){
	double matrix[16] = {1,0,0,0,0,1,0,0,0,0,1,0,x,y,z,1};
	glMultMatrixd(matrix);
}

void glScaled(double x, double y, double z){
	double matrix[16] = {x,0,0,0,0,y,0,0,0,0,z,0,0,0,0,1};
	glMultMatrixd(matrix);
}

void glFrustum(double l, double r, double b, double t, double n, double f ){
	double matrix[16] = {(2*n)/(r-l),0,0,0,0,(2*n)/(t-b),0,0,(r+l)/(r-l),(t+b)/(t-b),-(f+n)/(f-n),-1,0,0,-(2*f*n)/(f-n),0};
	glMultMatrixd(matrix);
} 

void glOrtho(double l, double r, double b, double t, double n, double f){
	double matrix[16] = {2/(r-l),0,0,0,0,2/(t-b),0,0,0,0,-(2/(f-n)),0,-(r+l)/(r-l),-(t+b)/(t-b),-(f+n)/(f-n),1};
	glMultMatrixd(matrix);
}

void glPushMatrix(){
	if(textflag == 1){
		TEXTCount++;
		pointer = texStack[TEXTCount].TextM;
		glLoadMatrix(texStack[TEXTCount - 1].TextM);
	}
	else if(mvflag == 1){
		MVStCount++;
		pointer = modVstack[MVStCount].ModelVM;
		glLoadMatrix(modVstack[MVStCount - 1].ModelVM);
	} else if(projflag == 1){
		PROJCount++;
		pointer = prjcStack[PROJCount].ProjM;
		glLoadMatrix(prjcStack[PROJCount - 1].ProjM);
	}
}

void glPopMatrix(){
	if(textflag == 1){
		TEXTCount--;
		pointer = texStack[TEXTCount].TextM;
	}
	else if(mvflag == 1){
		MVStCount--;
		pointer = modVstack[MVStCount].ModelVM;
	} else if(projflag == 1){
		PROJCount--;
		pointer = prjcStack[PROJCount].ProjM;
	}
}

double Norm(double v[]){
	return pow(pow(v[0],2)+pow(v[1],2)+pow(v[2],2),0.5);
}

void print4x4M(){
	int i, j;
	for (i = 0, j = 0; i < 16; j++){
		printf("%d ", pointer[i]);
		if((j+1) % 4 == 0){
			printf("\n");
			//getchar();
		}
		if(i == 15){
			i = 16;
		}
		else if(i + 4 > 15){
			i -= 11;
		}
		else{
			i+=4;
		}
	}
}