#include "RndImg_lib.h"

void getDimensions(int dim[]) {
  int i;
  printf("Please, digit the values for the dimension of the image:\n");
  for (i = 0; i < 2; ++i) {
    scanf("%d", &dim[i]);
  }
}

void createImage(int dim[]) {
  int i1, i2;
  time_t t;

  FILE *image = fopen("RndImg.ppm", "w+");
  fprintf(image, "P3\n");
  fprintf(image, "%d %d\n", dim[0], dim[1]);
  fprintf(image, "255\n");

  srand((unsigned)time(&t));

  for (i1 = 0; i1 < dim[0]; ++i1) {
    for (i2 = 0; i2 < dim[1]; ++i2) {
      fprintf(image, "%d %d %d ", rand() % 256, rand() % 256, rand() % 256);
    }
    fprintf(image, "\n");
  }

  fclose(image);
  // system("eog RndImg.ppm");
}