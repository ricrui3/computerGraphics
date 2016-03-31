#include "opengl.h"

void glBegin(char name[]){
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	%%
	%% Prototype of the Function void glBegin(char name[])
	%% Example of the function: glBegin(GL_LINES);
	%% This function prepare the program in order to receive points
	%% that will be transformed in lines, rectangles, etc.
	%%
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	if(name == "GL_LINES"){
		pointCount=0;
	}
}

void glVertex2ui(int x, int y){
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	%%
	%% Prototype of the Function void glVertex2ui(int x, int y)
	%% Example of the function: glVertex2ui(0,0);
	%% This function receives a point an store it on an array of 4
	%% elements, the first two positions are the values gave them by
	%% the programmer, the other two values are 0 and 1 by default.
	%%
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	ObjectCoord[pointCount][0] = x;
	ObjectCoord[pointCount][1] = y;
	ObjectCoord[pointCount][2] = 0;
	ObjectCoord[pointCount][3] = 1;
	pointCount++;
}

void glEnd(){
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	%%
	%% Prototype of the Function void glEnd()
	%% Example of the function: glEnd();
	%% This function call the needed functions to transform the
	%% object coordinates and to store them into the buffer and print
	%% them into the screen.
	%%
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	int aux = 0;
	int x1p, y1p, x2p, y2p;
	int posPoint1, posPoint2;
	for (;;)
	{
		posPoint1 = aux;
		aux++;
		posPoint2 = aux;
		aux++;
		FinalViewportTransformation(posPoint1);
		FinalViewportTransformation(posPoint2);
		x1p = normDevV[posPoint1][0];
		y1p = normDevV[posPoint1][1];
		x2p = normDevV[posPoint2][0];
		y2p = normDevV[posPoint2][1];
		SetLines(x1p,y1p,x2p,y2p);
		if(aux +1 > pointCount - 1) break;
	}
	CreateImage();
	system("eog LineImg.ppm &");
}

void glDepthRange(float n, float f){
	GLn = n;
	GLf = f;
}

void glViewPort(int x, int y, int w, int h){
	GLx = x;
	GLy = y;
	GLw = w;
	GLh = h;
	GLox = GLx+(GLw/2);
	GLoy = GLy+(GLh/2);
	GLpx = GLw;
	GLpy = GLh;
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

void CreateImage() {
	int width, height;

	FILE *image = fopen("LineImg.ppm", "w+");
	fprintf(image, "P3\n");
	fprintf(image, "%d %d\n", imgWidth, imgHeight);
	fprintf(image, "255\n");
 
	for (height = 0; height < imgHeight; ++height){
		for (width = 0; width < imgWidth; ++width){
				if(matrixBuff[width][height] == 0)
					fprintf(image, "%s", bgColour);
				else
					fprintf(image, "%s", lineColour);
		}
		fprintf(image, "\n");	
	}
	fclose(image);
}

void SetLines(int x0, int y0, int x1, int y1){
	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
	int err = (dx>dy ? dx : -dy)/2, e2;
	printf("(%d,%d),(%d,%d)\n", x0, y0, x1, y1);

	for(;;){
		if(x0 < imgWidth && x0 >= 0 && y0 < imgHeight && y0 >= 0){
			matrixBuff[x0][y0] = 1;
		}
		if (x0==x1 && y0==y1) break;
		e2 = err;
		if (e2 >-dx) { 
			err -= dy; x0 += sx; 
		}
		if (e2 < dy) { 
			err += dx; y0 += sy; 
		}
	}
}

void MakeIdentity(int original[16]){	
	original[1] = 1;
	original[6] = 1;
	original[11] = 1;
	original[16] = 1;	
}

void FinalViewportTransformation(p1){
	int auxVector[4];
	int i;
	float aux = 0;
	for (i = 0; i < 4; ++i)
	{
		auxVector[i] = ObjectCoord[p1][i];
	}

	//printf("x = %d, y = %d, z = %d, w = %d\n", auxVector[0], auxVector[1], auxVector[2], auxVector[3]);
	MatrixMult(auxVector, modVstack[MVStCount].ModelVM);
	for (i = 0; i < 4; ++i)
	{
		eyeCoord[i] = auxVector[i];
	}
	MatrixMult(auxVector, prjcStack[PROJCount].ProjM);
	for (i = 0; i < 3; ++i)
	{
		aux = auxVector[i] / auxVector[3];
		vertexNormalized[i] = aux;
	}
	normDevV[p1][0] = (GLpx / 2) * vertexNormalized[0] + GLox;
	normDevV[p1][1] = (GLpy / 2) * vertexNormalized[1] + GLoy;
	normDevV[p1][2] = ((GLf - GLn) / 2) * vertexNormalized[2] + (GLn + GLf)/2;
}

void MatrixMult(int Vector[], int matrix[16]){
	int i, j, k;
	int auxVector[4];

	for (i = 0; i < 4; ++i)
	{
		auxVector[i] = Vector[i];
	}

	for (i = 0; i < 4; ++i)
	{
		Vector[i] = 0;
		k = i;
		for (j = 0; j < 4; ++j)
		{
			Vector[i] += auxVector[j] * matrix[k];
			k += 4;
		}
	}
}