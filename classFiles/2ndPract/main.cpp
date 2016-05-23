#include "ImagePPM.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {

  if (argc != 4) {
    cout << "\nERROR: La forma correcta de ejecutar el programa es: " << argv[0]
         << " pixelesDeAncho pixelesDeAlto numeroRecursiones\n" << endl;
    exit(0);
  }

  ImagePPM image(atoi(argv[1]), atoi(argv[2]));
  image.setRandomValues();
  image.createImage();
  image.OctahedronRawFile((char *)"octahedron.raw");
  image.OctahedronRecursions(atoi(argv[3]));
  image.sphere.pointsNormalization();
  image.sphere.generateNewRAW();
  return 0;
}