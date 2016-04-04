#include "ImagePPM.h"
#include <stdlib.h>
#include <fcntl.h>
//#include <iostream>
using namespace std;

ImagePPM::ImagePPM(int width, int height) : dimX(width), dimY(height) {
  backgroundColor.setRGB(0, 0, 0);
  lineColor.setRGB(255, 255, 255);
  for (int i = 0; i < dimX; i++) {
    std::vector<Pixel> row;  // Create an empty row
    for (int j = 0; j < dimY; j++) {
      row.push_back(backgroundColor);  // Add an element (column) to the row
    }
    pixelMatrix.push_back(row);  // Add the row to the main vector
  }
}

void ImagePPM::createImage() {
  ofstream image;
  image.open("Image.ppm", ios::out | ios::trunc);
  image << "P3" << endl;
  image << dimX << " " << dimY << endl;
  image << "255" << endl;

  for (int i = 0; i < dimX; ++i) {
    for (int j = 0; j < dimY; ++j) {
      image << pixelMatrix[i][j].colorR << " " << pixelMatrix[i][j].colorG
            << " " << pixelMatrix[i][j].colorB << " ";
    }
    image << "\n";
  }

  image.close();
  // system("eog Image.ppm");
}

void ImagePPM::setRandomValues() {
  time_t t;

  srand((unsigned)time(&t));

  for (int i = 0; i < dimX; ++i) {
    for (int j = 0; j < dimY; ++j) {
      pixelMatrix[i][j].setRGB(rand() % 256, rand() % 256, rand() % 256);
    }
  }
}