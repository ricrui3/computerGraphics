#include "Pixel.h"

Pixel::Pixel(int cR, int cG, int cB) : colorR(cR), colorG(cG), colorB(cB) {}

Pixel::~Pixel() {}

void Pixel::setRGB(int cR, int cG, int cB) {
  colorR = cR;
  colorG = cG;
  colorB = cB;
}

void Pixel::setRGB(Pixel pixel){
  colorR = pixel.colorR;
  colorG = pixel.colorG;
  colorB = pixel.colorB;
}