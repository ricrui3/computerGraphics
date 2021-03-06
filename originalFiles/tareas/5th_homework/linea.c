#include "Naive.c"

int main(int argc, char const *argv[]) {
  if (argc != 5) {
    printf(
        "La forma correcta de ejecutar el programa es\n ./linea.c rotx roty "
        "rotz archivo.raw \n");
    exit(0);
  }
  FILE *RAWwwr;
  RAWwwr = fopen(argv[4], "r");

  int imgCounter = 2, degrees = 0;
  float PointCoord[3][4] = {0};
  int i, NoPoints = 0;

  // 3D Transformations---------
  SetIdentityAll();
  Rotation3Dx(atoi(argv[1]));
  Rotation3Dy(atoi(argv[2]));
  Rotation3Dz(atoi(argv[3]));
  Scaling3D(0.4, 0.4, 0.4);
  Translation3D(500, 500, 0);
  PrintMatrix(2);
  printf("\n");
  //---------------------------

  // 2D Transformations---------
  // Scaling2D(100,100);
  // Rotation2D(10);
  // Translation2D(250,250);
  // PrintMatrix(1);
  //---------------------------

  while (feof(RAWwwr) == 0) {
    for (i = 0; i < 3; ++i) {
      RAWreading(PointCoord, RAWwwr);
      // printf("\n %d) %f %f %f %f\n", i,PointCoord[k][0], PointCoord[k][1],
      // PointCoord[k][2], PointCoord[k][3]);
      MatrixVectMult4x4(PointCoord, TrasnfMatrix3D);
      // ProjectionMatrix(PointCoord, 2);
      // printf("%d) %f %f %f %f\n\n", i,PointCoord[k][0], PointCoord[k][1],
      // PointCoord[k][2], PointCoord[k][3]);
      k++;
      NoPoints++;
    }
    Point((int)(PointCoord[0][0] + 0.5), (int)(PointCoord[0][1] + 0.5),
          (int)(PointCoord[1][0] + 0.5), (int)(PointCoord[1][1] + 0.5));
    Point((int)(PointCoord[1][0] + 0.5), (int)(PointCoord[1][1] + 0.5),
          (int)(PointCoord[2][0] + 0.5), (int)(PointCoord[2][1] + 0.5));
    Point((int)(PointCoord[2][0] + 0.5), (int)(PointCoord[2][1] + 0.5),
          (int)(PointCoord[0][0] + 0.5), (int)(PointCoord[0][1] + 0.5));
    k = 0;
    // getchar();
  }
  fclose(RAWwwr);
  printf("Number of points scanned: %d\n", NoPoints);
  DrawTheDamnLine(imgCounter);
  degrees += 1;
  imgCounter++;
}
