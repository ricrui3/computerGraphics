#include "ImagePPM.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {

  if (argc != 3) {
    cout << "\nERROR: La forma correcta de ejecutar el programa es: " << argv[0]
         << " pixelesDeAncho pixelesDeAlto\n" << endl;
    exit(0);
  }

  ImagePPM image(atoi(argv[1]), atoi(argv[2]));
  image.setRandomValues();
  image.createImage();
  image.OctahedronRawFile((char *)"octahedron.raw");
  image.OctahedronRecursions(8);
  return 0;
}