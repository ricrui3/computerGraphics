#include "RndImg.c"

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    printf(
        "\nERROR: La forma correcta de ejecutar el programa es: %s "
        "pixelesDeAncho pixelesDeAlto\n\n",
        argv[0]);
    exit(0);
  }
  int dimension[2] = {atoi(argv[1]), atoi(argv[2])};
  // getDimensions(dimension);
  createImage(dimension);
}
