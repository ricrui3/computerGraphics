#include "ImagePPM.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sstream>
#include <string>
#include <iostream>
#include "Coordinate3D.h"
#include "Triangle.h"
#include "Sphere.h"
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
  system("eog Image.ppm");
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

void ImagePPM::readRawFile(char *Name) {
  ifstream model;
  model.open(Name);
  Sphere sphere;

  // Lee los puntos de cada triangulo de un archivo raw
  for (string line; getline(model, line);) {
    std::vector<Coordinate3D> coordinatesVector;
    double coordinates[9];

    // Lee los 9 float de una linea
    istringstream in(line);
    string type;
    in >> coordinates[0] >> coordinates[1] >> coordinates[2] >>
        coordinates[3] >> coordinates[4] >> coordinates[5] >> coordinates[6] >>
        coordinates[7] >> coordinates[8];

    // Guarda cada tercia de valores en un objeto coordenada
    sphere.triangulation.push_back(Triangle(coordinates));
  }
  sphere.generateRAW();
}