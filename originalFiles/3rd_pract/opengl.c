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

void MakeIdentity(int original[4][4]){	
	original[0][0] = 1;
	original[1][1] = 1;
	original[2][2] = 1;
	original[3][3] = 1;	
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
	MatrixMult(auxVector, ModelVM);
	for (i = 0; i < 4; ++i)
	{
		eyeCoord[i] = auxVector[i];
	}
	MatrixMult(auxVector, ProjM);
	for (i = 0; i < 3; ++i)
	{
		aux = auxVector[i] / auxVector[3];
		vertexNormalized[i] = aux;
	}
	normDevV[p1][0] = (GLpx / 2) * vertexNormalized[0] + GLox;
	normDevV[p1][1] = (GLpy / 2) * vertexNormalized[1] + GLoy;
	normDevV[p1][2] = ((GLf - GLn) / 2) * vertexNormalized[2] + (GLn + GLf)/2;
}

void MatrixMult(int Vector[], int matrix[4][4]){
	int i,j;
	int auxVector[4];

	for (i = 0; i < 4; ++i)
	{
		auxVector[i] = Vector[i];
	}

	for (i = 0; i < 4; ++i)
	{
		Vector[i] = 0;
		for (j = 0; j < 4; ++j)
		{
			Vector[i] += auxVector[j] * matrix[i][j];
		}
	}
}