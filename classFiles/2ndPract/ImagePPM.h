#ifndef IMAGE_PPM_H_
#define IMAGE_PPM_H_
#include "Pixel.h"
#include <vector>
#include "Sphere.h"

class ImagePPM {
 private:
  int dimX;
  int dimY;
  Pixel backgroundColor;
  Pixel lineColor;

 public:
  Sphere sphere;
  std::vector<std::vector<Pixel> > pixelMatrix;
  ImagePPM(int = 100, int = 100);
  void createImage();
  void setRandomValues();
  void OctahedronRawFile(char *Name);
  void setBackgroundColor(Pixel bckgC) { backgroundColor = bckgC; }
  void setLineColor(Pixel lineC) { lineColor = lineC; }
  void OctahedronRecursions(int rec);
};

#endif
