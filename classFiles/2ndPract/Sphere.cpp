#include "Sphere.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Coordinate3D.h"
using namespace std;

Sphere::Sphere() {}

Sphere::~Sphere() {}

void Sphere::recursiveTriangles() {
  int numTriangles = triangulation.size();
  std::vector<Triangle> auxTriangulation;
  for (int i = 0; i < numTriangles; ++i) {
    triangulation[i].dividedTriangle(&auxTriangulation);
  }
  triangulation = auxTriangulation;
}

void Sphere::readRawFile(char *Name) {
  ifstream model;
  model.open(Name);

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
    triangulation.push_back(Triangle(coordinates));
  }
}
int archiveNumber = 0;
void Sphere::generateNewRAW() {
  char archiveName[31];
  ofstream sphereRAW;
  sprintf(archiveName, "./generatedFiles/sphere%d.raw", archiveNumber++);
  sphereRAW.open(archiveName, ios::out | ios::trunc);
  int numTriangles = triangulation.size();

  for (int i = 0; i < numTriangles; ++i) {
    //cout << triangulation[i].triangleToString() << endl;
    sphereRAW << triangulation[i].triangleToString();
    sphereRAW << "\n";
  }

  sphereRAW.close();
}

void Sphere::pointsNormalization(){

}