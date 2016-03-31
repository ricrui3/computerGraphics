#include "opengl.h"

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