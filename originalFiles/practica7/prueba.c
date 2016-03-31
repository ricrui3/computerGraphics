#include "opengl.c"

int main(int argc, char const *argv[])
{
	int i, numofpoints = 0;
	float n;
	FILE *pikachu;
	pikachu = fopen("portal.raw","r");
	int count = 0, count2 = 0;
	float f = 50;

	float PointCoord[3][4] = {0,0,0,1};
	float (*p)[4];

	float ProjoMatrix[16] = {1,0,0,0,0,1,0,0,0,0,1,(1/f),0,0,0,0};

	glDepthRange(0,1);
	glViewPort(0,0,2,2);
	glMatrixMode(MODELVIEW);
	glLoadIdentity();
	glMatrixMode(PROJECTION);
	glLoadMatrixf(ProjoMatrix);
	glTranslated(60, 60, 60);
	glScaled(100, 100, 100);

	glBegin(GL_LINES);

		while(feof(pikachu)==0){
			for (i = 0; i < 3; ++i)
			{
				RAWreading(PointCoord[i], pikachu);
				printf("%f, %f, %f, %f\n", PointCoord[i][0], PointCoord[i][1], PointCoord[i][2], PointCoord[i][3]);
				p = &PointCoord[i];
				printf("%f, %f, %f, %f\n", PointCoord[i][0], PointCoord[i][1], PointCoord[i][2], PointCoord[i][3]);
				count2 = 0;
				numofpoints++;
				//getchar();
			}

			glVertex2ui(PointCoord[0][0], PointCoord[0][1]);
			glVertex2ui(PointCoord[1][0], PointCoord[1][1]);
			glVertex2ui(PointCoord[1][0], PointCoord[1][1]);
			glVertex2ui(PointCoord[2][0], PointCoord[2][1]);
			glVertex2ui(PointCoord[2][0], PointCoord[2][1]);
			glVertex2ui(PointCoord[0][0], PointCoord[0][1]);
		}
		fclose(pikachu);
		printf("numero de puntos = %d\n", numofpoints);
		getchar();
	glEnd();
	return 0;
}