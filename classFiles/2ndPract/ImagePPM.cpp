#include "ImagePPM.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sstream>
#include <string>
#include <iostream>
#include "Coordinate3D.h"
//#include "Triangulo.h"
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
  // std::vector<Triangulo> coordinates;

  // Lee los puntos de cada triengulo de un archivo raw
  for (string line; getline(model, line);) {
    std::vector<Coordinate3D> coordinatesVector;
    double coordinate[9];

    // Lee los 9 float de una linea
    istringstream in(line);
    string type;
    in >> coordinate[0] >> coordinate[1] >> coordinate[2] >> coordinate[3] >>
        coordinate[4] >> coordinate[5] >> coordinate[6] >> coordinate[7] >>
        coordinate[8];

    // Guarda cada tercia de valores en un objeto coordenada
    coordinatesVector.push_back(
        Coordinate3D(coordinate[0], coordinate[1], coordinate[2]));
    coordinatesVector.push_back(
        Coordinate3D(coordinate[3], coordinate[4], coordinate[5]));
    coordinatesVector.push_back(
        Coordinate3D(coordinate[6], coordinate[7], coordinate[8]));

    cout << coordinatesVector[0].toString() << " "
         << coordinatesVector[1].toString() << " "
         << coordinatesVector[2].toString() << endl;
  }
}