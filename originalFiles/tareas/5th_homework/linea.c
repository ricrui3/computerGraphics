#include "Naive.c"

main(){
		FILE *RAWwwr;
		RAWwwr = fopen("portal.raw","r");

		int imgCounter = 2, degrees = 0;
		float PointCoord[3][4] = {0};
		int count, i, j, NoPoints = 0;
		int focalLenght;

		//3D Transformations---------
		SetIdentityAll();
		Rotation3Dx(10);
		Rotation3Dy(10);
		Rotation3Dz(50);
		Scaling3D(100,100,0);
		Translation3D(250,250,0);
		PrintMatrix(2);
		printf("\n");
		//---------------------------

		//2D Transformations---------
		//Scaling2D(100,100);
		//Rotation2D(10);
		//Translation2D(250,250);
		//PrintMatrix(1);
		//---------------------------

		while(feof(RAWwwr)==0){
			for (i = 0; i < 3; ++i)
			{
				RAWreading(PointCoord, RAWwwr);
				//printf("\n %d) %f %f %f %f\n", i,PointCoord[k][0], PointCoord[k][1], PointCoord[k][2], PointCoord[k][3]);
				MatrixVectMult4x4(PointCoord, TrasnfMatrix3D);
				//ProjectionMatrix(PointCoord, 2);
				//printf("%d) %f %f %f %f\n\n", i,PointCoord[k][0], PointCoord[k][1], PointCoord[k][2], PointCoord[k][3]);
				k++; NoPoints++;
			}
			Point((int)(PointCoord[0][0] + 0.5), (int)(PointCoord[0][1] + 0.5), (int)(PointCoord[1][0] + 0.5), (int)(PointCoord[1][1] + 0.5));
			Point((int)(PointCoord[1][0] + 0.5), (int)(PointCoord[1][1] + 0.5), (int)(PointCoord[2][0] + 0.5), (int)(PointCoord[2][1] + 0.5));
			Point((int)(PointCoord[2][0] + 0.5), (int)(PointCoord[2][1] + 0.5), (int)(PointCoord[0][0] + 0.5), (int)(PointCoord[0][1] + 0.5));
			k = 0;
			//getchar();
		}
		fclose(RAWwwr);
		printf("Number of points scanned: %d\n", NoPoints);
		DrawTheDamnLine(imgCounter);
		degrees += 1;
		imgCounter++;
}