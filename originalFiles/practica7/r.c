#include<stdio.h>
#include<stdlib.h>

void RAWreading(float point[], FILE *pikachu);

int main(int argc, char const *argv[])
{
	float n;
	FILE *pikachu;
	pikachu = fopen("portalgun2.raw","r");
	//fscanf(pikachu, "%f",&n);
	//printf("%f\n", n);
	int count = 0;
	float PointCoord[4] = {0,0,0,1};
	while(feof(pikachu)==0){
		RAWreading(PointCoord, pikachu);
		printf("%f, %f, %f, %f\n", PointCoord[0], PointCoord[1], PointCoord[2], PointCoord[3]);
		if(count == 100){
			getchar();
			count = 0;
		}
		count++;
	}
	fclose(pikachu);
}

void RAWreading(float point[], FILE *pikachu){
	float n;
	int aux;
	int i=0;
	while(i < 3)
	{
		switch(i){
			case 0:
				fscanf(pikachu, "%f",&n);
				point[0] = n;
				break;
			case 1:
				fscanf(pikachu, "%f",&n);
				point[1] = n;
				break;
			case 2:
				fscanf(pikachu, "%f",&n);
				point[2] = n;
				break;
		}
		i++;
	}
}
