#include "Naive.c"

main(){
	int imgCounter = 1, degrees = 0;
	while(imgCounter < 100){
		FILE *RAWwwr;
		RAWwwr = fopen("cube.raw","r");
		float PointCoord[3][4] = {0};
		int count, i, j, NoPoints = 0;

		//printf("\n");
		SetIdentityAll();
		Scaling2D(100,100);
		Rotation2D(degrees);
		Translation2D(250,250);
		//PrintMatrix();


		while(feof(RAWwwr)==0){
			for (i = 0; i < 3; ++i)
			{
				RAWreading(PointCoord, RAWwwr);
				//printf("%d) %f %f %f %f\n", i,PointCoord[k][0], PointCoord[k][1], PointCoord[k][2], PointCoord[k][3]);
				MatrixVectMult(PointCoord, TrasnformationMatrix);
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
		//printf("Number of points scanned: %d\n", NoPoints);
		DrawTheDamnLine(imgCounter);
		degrees += 1;
		imgCounter++;
	}
}