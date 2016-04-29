#include "Sphere.h"
#include <iostream>
#include <fstream>
#include "Coordinate3D.h"
using namespace std;

Sphere::Sphere(int numR) : numRecursions(numR) {
  cout << "Esfera Creada" << endl;
}

Sphere::~Sphere() {}

void Sphere::recursiveTriangles() {
  int numTriangles = triangulation.size();
  std::vector<Triangle> auxTriangulation;
  for (int i = 0; i < numTriangles; ++i) {
    triangulation[i].dividedTriangle(&auxTriangulation);
  }
  triangulation = auxTriangulation;
}

void Sphere::generateRAW() {
  ofstream sphereRAW;
  sphereRAW.open("./generatedFiles/sphere.raw", ios::out | ios::trunc);
  int numTriangles = triangulation.size();

  for (int i = 0; i < numTriangles; ++i) {
    sphereRAW << triangulation[i].triangleToString();
    sphereRAW << "\n";
  }

  sphereRAW.close();
}