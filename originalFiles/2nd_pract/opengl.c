#include "opengl.h"

void glBegin(char name[]){
	if(name == "GL_LINES"){
		pointCount=0;
	}
}

void glVertex2ui(int x, int y){	
	points[pointCount] = x;
	pointCount++;
	points[pointCount] = y;
	pointCount++;
}

void glEnd(){
	int aux = 0;
	int xp1, yp1, xp2, yp2;
	for (;;)
	{
		xp1 = points[aux]; aux++;
		yp1 = points[aux]; aux++;
		xp2 = points[aux]; aux++;
		yp2 = points[aux];
		SetLines(xp1, yp1, xp2, yp2);
		if(aux + 3 > pointCount - 1) break;
		aux++;
	}
	CreateImage();
	system("eog LineImg.ppm");
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