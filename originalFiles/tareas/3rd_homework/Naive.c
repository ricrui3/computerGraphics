#include "Naive.h"

int NaiveA(int x1p, int y1p, int x2p, int y2p){
	float m = 0, b;
	int x, y;
	int swapOp = 0;

	if(y1p == y2p){
		printf("Vertical line\n");
		SpecialCase(1, x1p, y1p, x2p, y2p, 0, 0, 0);
		return 1;
	}
	if(x1p == x2p){
		printf("Horizontal line\n");
		SpecialCase(2, x1p, y1p, x2p, y2p, 0, 0, 0);
		return 2;
	}

	CalculateM(&m, x1p, y1p, x2p, y2p);
	printf("m = %f\n", m);

	if(m < 0){
		printf("m < 0\n");
		if(x1p < x2p){
			swap(&y1p,&y2p);
			CalculateM(&m, x1p, y1p, x2p, y2p);
			printf("1m = %f\n", m);
			CalculateB(&b, y2p, m, x1p);
			swapOp = 1;
		}
		else{
			swap(&x1p, &x2p);
			CalculateM(&m, x1p, y1p, x2p, y2p);
			printf("2m = %f\n", m);
			CalculateB(&b, y2p, m, x1p);
			swapOp = 1;
		}
	}

	if(m == 1){
		printf("m = 1\n");
		SpecialCase(3, x1p, y1p, x2p, y2p, 0, 0, swapOp);
		return 3;
	}

	if(m > 1){
		printf("m > 1\n");
		swap(&x1p, &y1p);
		swap(&x2p, &y2p);
		CalculateM(&m, x1p, y1p, x2p, y2p);
		CalculateB(&b, y1p, m, x1p);
		printf("m = %f b = %f\n", m, b);
		swapOp = swapOp == 1 ? 3 : 2;
	}

	printf("x = %d y = %d m = %f b = %f\n", x1p, y1p, m, b);
	SpecialCase(4, x1p, y1p, x2p, y2p, m, b, swapOp);
}

void SpecialCase(int option,int x1p,int y1p,int x2p,int y2p,float m,float b,int swapOp){
	int x, y, xaux, yaux;
	int dx, dy, e;
	int width, height;
	int flag = 0;

	switch(option){
		case 1:
			if(x1p > x2p){
				swap(&x1p, &x2p);
			}
			printf("SpecialCase #1\n");
			for(x = x1p; x <= x2p; x++){
				matrixBuff[x][imgHeight - y1p] = 1;
			}
		break;

		case 2:
			if(y1p > y2p){
				swap(&y1p, &y2p);
			}
			//printf("x1 = %d y1 = %d x2 = %d y2 = %d\n", x1p, y1p, x2p, y2p);
			for(y = y1p; y < y2p; y++){
				matrixBuff[x1p][imgWidth - y] = 1;
			}
			printf("SpecialCase #2\n");
		break;

		case 3:
			if(x1p > x2p){
				swap(&x1p, &x2p);
				swap(&y1p, &y2p);
			}
			for (x = x1p, y = y1p, yaux = y2p; x < x2p; x++, y++, yaux--)
			{	
				if(swapOp == 0)
					matrixBuff[x][imgHeight - y] = 1;
				else{
					matrixBuff[x][imgHeight - yaux] = 1;
				}
			}
			printf("SpecialCase #%d\n", option);
		break;

		case 4:
			printf("option = 4\n");
			dx = x2p - x1p;
			dy = y2p - y1p;
			e = 0;
			y = y1p;

			for (x = x1p; x <= x2p; x++)
			{	
				switch(swapOp){
					case 0:
						matrixBuff[x][imgHeight - y] = 1;
						e += dy;
						if((e<<1)>= dx){
							y++;
							e -= dx;
						}
						if(flag == 0){
							printf("swap #%d\n", swapOp);
							flag = 1;
						}
						break;
					case 1:
						yaux = (m*xaux) + b;
						matrixBuff[x][imgHeight - yaux] = 1;
						if(flag == 0){
							printf("swap #%d\n", swapOp);
							flag = 1;
						}
						break;
					case 2:
						matrixBuff[y][imgHeight - x] = 1;
						e += dy;
						if((e<<1)>= dx){
							y++;
							e -= dx;
						}
						if(flag == 0){
							printf("swap #%d\n", swapOp);
							flag = 1;
						}
						break;
					case 3:
						yaux = (m*xaux) + b;
						matrixBuff[yaux][imgHeight - x] = 1;
						if(flag == 0){
							printf("swap #%d\n", swapOp);
							flag = 1;
						}
						break;
				}
			}
			printf("SpecialCase #%d\n", option);
		break;
	}
}

void CalculateM(float *mAux, int x1p, int y1p, int x2p, int y2p){
	*mAux = (float) (y2p - y1p) / (float) (x2p - x1p);
}

void CalculateB(float *b, int y1p, float m, int x1p){
	*b = (float)y1p - (float)(m * x1p);
}

void swap(int *punto1, int *punto2){
	int c;
	c = *punto1;
	*punto1 = *punto2;
	*punto2 = c;
}

void DrawTheDamnLine(){
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
	printf("here\n");
	fclose(image);
	system("eog LineImg.ppm&");
}