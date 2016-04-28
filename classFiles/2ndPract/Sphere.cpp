#include "Sphere.h"
#include <iostream>
#include <fstream>
using namespace std;

Sphere::Sphere() {
  cout << "Esfera Creada" << endl;
}

Sphere::~Sphere(){}

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