#ifndef IMAGE_PPM_H_
#define IMAGE_PPM_H_
#include "Pixel.h"
#include <vector>
#include <fstream>

class ImagePPM {
 private:
  int dimX;
  int dimY;
  Pixel backgroundColor;
  Pixel lineColor;

 public:
  std::vector<std::vector<Pixel> > pixelMatrix;
  ImagePPM(int = 100, int = 100);
  void createImage();
  void setRandomValues();
  void readRawFile(char *Name);
  void setBackgroundColor(Pixel bckgC) { backgroundColor = bckgC; }
  void setLineColor(Pixel lineC) { lineColor = lineC; }
};

#endif
