#include "Naive.h"

void RAWreading(float point[3][4], FILE *RAWwwr){
	float n;
	int aux;
	int i = 0;
	while(i < 4){
		switch(i){
			case 0:
				fscanf(RAWwwr, "%f",&n);
				point[k][0] = n;
				break;
			case 1:
				fscanf(RAWwwr, "%f",&n);
				point[k][1] = n;
				break;
			case 2:
				fscanf(RAWwwr, "%f",&n);
				point[k][2] = n;
				break;
			case 3:
				point[k][3] = 1;
				break;
		}
		i++;
	}
}

void SetIdentityAll(){
	int i, j;
	for ( i = 0; i < 3; ++i){
		for ( j = 0; j < 3; ++j){
			Translation2DMatrix[i][j] = 0;
			Scaling2DMatrix[i][j] = 0;
			Rotation2DMatrix[i][j] = 0;
			TrasnformationMatrix[i][j] = 0;
		}
	}

	for (j = 0; j < 3; ++j){
		Translation2DMatrix[j][j] = 1;
		Scaling2DMatrix[j][j] = 1;
		Rotation2DMatrix[j][j] = 1;
		TrasnformationMatrix[j][j] = 1;
	}

	for (i = 0; i < imgHeight; ++i){
		for (j = 0; j < imgWidth; ++j){
			matrixBuff[i][j] = 0;
		}
	}
}

void Translation2D(float TransX, float TransY){
	Translation2DMatrix[0][2] = TransX;
	Translation2DMatrix[1][2] = TransY;
	Matrix3x3Mult(Translation2DMatrix);
}

void Scaling2D(float ScaleX, float ScaleY){
	Scaling2DMatrix[0][0] = ScaleX;
	Scaling2DMatrix[1][1] = ScaleY;
	Matrix3x3Mult(Scaling2DMatrix);
}
void Rotation2D(float rotDeg){
	Rotation2DMatrix[0][0] = cos(rotDeg);
	Rotation2DMatrix[0][1] = sin(rotDeg);
	Rotation2DMatrix[1][0] = -sin(rotDeg);
	Rotation2DMatrix[1][1] = cos(rotDeg);
	Matrix3x3Mult(Rotation2DMatrix);
}

void MatrixVectMult(float Vector[3][4], float matrix[3][3]){
	int i, j;
	float auxVector[3];

	for (i = 0; i < 3; ++i){
		if(i == 2 && Vector[k][2] != 1){
			auxVector[i] = 1;
			continue;
		}
		auxVector[i] = Vector[k][i];
	}

	for (i = 0; i < 3; ++i){
		Vector[k][i] = 0;
		for (j = 0; j < 3; ++j){
			Vector[k][i] += auxVector[j] * matrix[i][j];
		}
	}
}

void Matrix3x3Mult(float matrix[3][3]){
	int i, j, l;
	float auxMatrix[3][3];

	for (i = 0; i < 3; ++i){
		for (j = 0; j < 3; ++j){
			auxMatrix[i][j] = TrasnformationMatrix[i][j];
			TrasnformationMatrix[i][j] = 0;
		}
	}

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            for(l = 0; l < 3; l++){
                TrasnformationMatrix[i][j] +=  matrix[i][l] *  auxMatrix[l][j];
            }
        }
    }
}

void Translation3D(float TransX, float TransY, float TransZ){
	Translation3DMatrix[0][3] = TransX;
	Translation3DMatrix[1][3] = TransY;
	Translation3DMatrix[2][3] = TransZ;
	Matrix4x4Mult(Translation3DMatrix);
}

void Scaling3D(float ScaleX, float ScaleY, float ScaleZ){
	Scaling3DMatrix[0][0] = ScaleX;
	Scaling3DMatrix[1][1] = ScaleY;
	Scaling3DMatrix[2][2] = ScaleZ;
	Matrix4x4Mult(Scaling3DMatrix);
}
void Rotation3Dx(float rotDeg){
	Rotation3DxMatrix[1][1] = cos(rotDeg);
	Rotation3DxMatrix[1][2] = sin(rotDeg);
	Rotation3DxMatrix[2][1] = -sin(rotDeg);
	Rotation3DxMatrix[2][2] = cos(rotDeg);
	Matrix4x4Mult(Rotation3DxMatrix);
}

void Rotation3Dy(float rotDeg){
	Rotation3DyMatrix[0][0] = cos(rotDeg);
	Rotation3DyMatrix[0][2] = sin(rotDeg);
	Rotation3DyMatrix[2][0] = -sin(rotDeg);
	Rotation3DyMatrix[2][2] = cos(rotDeg);
	Matrix4x4Mult(Rotation3DyMatrix);
}

void Rotation3Dz(float rotDeg){
	Rotation3DzMatrix[0][0] = cos(rotDeg);
	Rotation3DzMatrix[0][1] = sin(rotDeg);
	Rotation3DzMatrix[1][0] = -sin(rotDeg);
	Rotation3DzMatrix[1][1] = cos(rotDeg);
	Matrix4x4Mult(Rotation3DzMatrix);
}

void ProjectionMatrix(float Vector[3][4], float focalLenght){
	ProjMatrix[3][2] = (1/focalLenght);
	ProjMatrix[3][3] = 0;
	MatrixVectMult4x4(Vector,ProjMatrix);
}

void MatrixVectMult4x4(float Vector[3][4], float matrix[4][4]){
	int i, j;
	float auxVector[4];

	for (i = 0; i < 4; ++i){
		auxVector[i] = Vector[k][i];
	}

	for (i = 0; i < 4; ++i){
		Vector[k][i] = 0;
		for (j = 0; j < 4; ++j){
			Vector[k][i] += auxVector[j] * matrix[i][j];
		}
	}

	if(Vector[k][3] != 0){
		for (i = 0; i < 3; ++i)
		{
			Vector[k][i] = (Vector[k][i] / Vector[k][3]);
		}
	}
	
}

void Matrix4x4Mult(float matrix[4][4]){
	int i, j, l;
	float auxMatrix[4][4];

	for (i = 0; i < 4; ++i){
		for (j = 0; j < 4; ++j){
			auxMatrix[i][j] = TrasnfMatrix3D[i][j];
			TrasnfMatrix3D[i][j] = 0;
		}
	}

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            for(l = 0; l < 4; l++){
                TrasnfMatrix3D[i][j] +=  matrix[i][l] *  auxMatrix[l][j];
            }
        }
    }
}

void PrintMatrix(int option){
	int i,j;
	if(option == 1){
		printf("--------------------\n");
		printf("TrasnformationMatrix 2D\n");
		printf("--------------------\n");
		for (i = 0; i < 3; ++i){
			for (j = 0; j < 3; ++j){
				printf("%f ", TrasnformationMatrix[i][j]);
			}
			printf("\n");
		}
		//getchar();
	}
	else if(option == 2){
		printf("--------------------\n");
		printf("TrasnformationMatrix 3D\n");
		printf("--------------------\n");
		for (i = 0; i < 4; ++i){
			for (j = 0; j < 4; ++j){
				printf("%f ", TrasnfMatrix3D[i][j]);
			}
			printf("\n");
		}
	}
	else{
		printf("error\n");
	}
}


int Point(int x1p, int y1p, int x2p, int y2p){
	float m = 0, b;
	int x, y;
	int swapOp = 0;

	//printf("(%d, %d) (%d, %d)\n", x1p, y1p, x2p, y2p);

	if(y1p == y2p){
		//printf("Vertical line\n");
		SpecialCase(1, x1p, y1p, x2p, y2p, 0, 0, 0);
		return 1;
	}
	if(x1p == x2p){
		//printf("Horizontal line\n");
		SpecialCase(2, x1p, y1p, x2p, y2p, 0, 0, 0);
		return 2;
	}

	CalculateM(&m, x1p, y1p, x2p, y2p);
	//printf("m = %f\n", m);

	if(m < 0){
		//printf("m < 0\n");
		if(x1p < x2p){
			swap(&y1p,&y2p);
			CalculateM(&m, x1p, y1p, x2p, y2p);
			//printf("1m = %f\n", m);
			swapOp = 1;
		}
		else{
			swap(&x1p, &x2p);
			CalculateM(&m, x1p, y1p, x2p, y2p);
			//printf("2m = %f\n", m);
			CalculateB(&b, y2p, m, x1p);
			swapOp = 1;
		}
	}

	if(m == 1){
		//printf("m = 1\n");
		SpecialCase(3, x1p, y1p, x2p, y2p, 0, 0, swapOp);
		return 3;
	}

	if(m > 1){
		//printf("m > 1\n");
		swap(&x1p, &y1p);
		swap(&x2p, &y2p);
		CalculateM(&m, x1p, y1p, x2p, y2p);
		//printf("m = %f\n", m);
		swapOp = swapOp == 1 ? 3 : 2;
	}

	//printf("x = %d y = %d m = %f \n", x1p, y1p, m);
	SpecialCase(4, x1p, y1p, x2p, y2p, m, b, swapOp);
}

void SpecialCase(int option,int x1p,int y1p,int x2p,int y2p,float m,float b,int swapOp){
	int x, xaux;
	float y, yaux;
	int width, height;
	int flag = 0;

	switch(option){
		case 1:
			if(x1p > x2p){
				swap(&x1p, &x2p);
			}
			//printf("SpecialCase #1\n");
			for(x = x1p; x <= x2p; x++){
				if(x > 0 && y1p > 0 && y1p <= imgWidth && x <= imgHeight)
					matrixBuff[x][imgHeight - y1p] = 1;
			}
		break;

		case 2:
			//printf("SpecialCase #2\n");
			if(y1p > y2p){
				swap(&y1p, &y2p);
			}
			if(y1p < 0){
				y1p = 0;
			}
			if(y2p < 0){
				y2p = 0;
			}
			if(x1p > 0){
				for(y = y1p; y < y2p; y++){
					if(x1p > 0 && y > 0 && y <= imgWidth && x1p <= imgHeight)
						matrixBuff[x1p][imgWidth - (int)y] = 1;
				}
			}
		break;

		case 3:
			//printf("SpecialCase #3\n", option);
			if(x1p > x2p){
				swap(&x1p, &x2p);
				swap(&y1p, &y2p);
			}
			for (x = x1p, y = y1p, yaux = y2p; x < x2p; x++, y++, yaux--){	
				if(swapOp == 0)
					if(x > 0 && y > 0 && y <= imgWidth && x <= imgHeight)
						matrixBuff[x][imgHeight - (int)y] = 1;
				else{
					if(x > 0 && yaux > 0 && y <= imgWidth && x <= imgHeight)
						matrixBuff[x][imgHeight - (int)yaux] = 1;
				}
			}
		break;

		case 4:
			//printf("option = 4\n");
			//printf("(%d, %d) (%d, %d) %f\n", x1p, y1p, x2p, y2p, m);
			if(x1p > x2p){
				swap(&x1p, &x2p);
				swap(&y1p, &y2p);
			}

			//printf("(%d, %d) (%d, %d) %f\n", x1p, y1p, x2p, y2p, m);
			for (x = x1p, yaux = y2p, y = y1p; x <= x2p; x++, xaux--){	
				switch(swapOp){
					case 0:
						if(flag == 0){
							//printf("swap #%d\n", swapOp);
							flag = 1;
						}
						y += m;
						if(x > 0 && y > 0 && y <= imgWidth && x <= imgHeight)
							matrixBuff[x][imgHeight - (int)y] = 1;
						break;
					case 1:
						if(flag == 0){
							//printf("swap #%d\n", swapOp);
							flag = 1;
						}
						y += m;
						yaux -= m;
						if(x > 0 && yaux > 0)
							if(x > 0 && yaux > 0 && yaux <= imgWidth && x <= imgHeight)
								matrixBuff[x][imgHeight - (int)yaux] = 1;
						break;
					case 2:
						if(flag == 0){
							//printf("swap #%d\n", swapOp);
							flag = 1;
						}
						y += m;
						if(x > 0 && y > 0 && y <= imgWidth && x <= imgHeight)
							matrixBuff[(int)y][imgHeight - x] = 1;
						//printf("D:\n");
						break;
					case 3:
						if(flag == 0){
							//printf("swap #%d\n", swapOp);
							flag = 1;
						}
						yaux -= m;
						if(yaux > 0)
							if(x > 0 && yaux > 0 && y <= imgWidth && x <= imgHeight)
								matrixBuff[(int)yaux][imgHeight - x] = 1;
						break;
				}
			}
			//printf("SpecialCase #%d\n", option);
		break;
	}
	//printf("\n");
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

void DrawTheDamnLine(int NoImg){
	int width, height;
	char NameImg[20];
	sprintf(NameImg, "LineImg%d.ppm", NoImg);
	FILE *image = fopen(NameImg, "w+");
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
	//printf("here\n");
	fclose(image);
	sprintf(NameImg, "eog LineImg%d.ppm&", NoImg);
	system(NameImg);
}

