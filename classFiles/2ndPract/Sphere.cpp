#include "Sphere.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;

double distanceTwo3dPoints(Coordinate3D point1, Coordinate3D point2);

Sphere::Sphere() { sphereRadius = 1; }

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
  int highestPoint = 0;
  int lowestPoint = 0;

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
  //It finds the highest and the lowest point in the Y axis
  for (int i = 0; i < 5; ++i) {
    if (triangulation[i].getCoord1()->getY() > highestPoint) {
      highestPoint = triangulation[i].getCoord1()->getY();
    } else if (triangulation[i].getCoord1()->getY() < lowestPoint) {
      lowestPoint = triangulation[i].getCoord1()->getY();
    }
    if (triangulation[i].getCoord2()->getY() > highestPoint) {
      highestPoint = triangulation[i].getCoord2()->getY();
    } else if (triangulation[i].getCoord2()->getY() < lowestPoint) {
      lowestPoint = triangulation[i].getCoord2()->getY();
    }
    if (triangulation[i].getCoord3()->getY() > highestPoint) {
      highestPoint = triangulation[i].getCoord3()->getY();
    } else if (triangulation[i].getCoord3()->getY() < lowestPoint) {
      lowestPoint = triangulation[i].getCoord3()->getY();
    }
  }
  sphereCenter.setY((highestPoint + lowestPoint) / 2);
  sphereRadius = distanceTwo3dPoints(Coordinate3D(0,0,0), highestPoint);
  //It finds the rightest and the leftest point
  highestPoint = 0;
  lowestPoint = 0;
  for (int i = 0; i < 5; ++i) {
    if (triangulation[i].getCoord1()->getX() > highestPoint) {
      highestPoint = triangulation[i].getCoord1()->getX();
    } else if (triangulation[i].getCoord1()->getX() < lowestPoint) {
      lowestPoint = triangulation[i].getCoord1()->getX();
    }
    if (triangulation[i].getCoord2()->getX() > highestPoint) {
      highestPoint = triangulation[i].getCoord2()->getX();
    } else if (triangulation[i].getCoord2()->getX() < lowestPoint) {
      lowestPoint = triangulation[i].getCoord2()->getX();
    }
    if (triangulation[i].getCoord3()->getX() > highestPoint) {
      highestPoint = triangulation[i].getCoord3()->getX();
    } else if (triangulation[i].getCoord3()->getX() < lowestPoint) {
      lowestPoint = triangulation[i].getCoord3()->getX();
    }
  }
  sphereCenter.setX((highestPoint + lowestPoint) / 2);
  //It finds the closest and the farthest point
  highestPoint = 0;
  lowestPoint = 0;
  for (int i = 0; i < 5; ++i) {
    if (triangulation[i].getCoord1()->getZ() > highestPoint) {
      highestPoint = triangulation[i].getCoord1()->getZ();
    } else if (triangulation[i].getCoord1()->getZ() < lowestPoint) {
      lowestPoint = triangulation[i].getCoord1()->getZ();
    }
    if (triangulation[i].getCoord2()->getZ() > highestPoint) {
      highestPoint = triangulation[i].getCoord2()->getZ();
    } else if (triangulation[i].getCoord2()->getZ() < lowestPoint) {
      lowestPoint = triangulation[i].getCoord2()->getZ();
    }
    if (triangulation[i].getCoord3()->getZ() > highestPoint) {
      highestPoint = triangulation[i].getCoord3()->getZ();
    } else if (triangulation[i].getCoord3()->getZ() < lowestPoint) {
      lowestPoint = triangulation[i].getCoord3()->getZ();
    }
  }
  sphereCenter.setZ((highestPoint + lowestPoint) / 2);

  cout << sphereCenter.toString() << " sphereRadius: " << sphereRadius << endl;
}

int archiveNumber = 0;
void Sphere::generateNewRAW() {
  char archiveName[31];
  ofstream sphereRAW;
  sprintf(archiveName, "./generatedFiles/sphere%d.raw", archiveNumber++);
  sphereRAW.open(archiveName, ios::out | ios::trunc);
  int numTriangles = triangulation.size();

  for (int i = 0; i < numTriangles; ++i) {
    // cout << triangulation[i].triangleToString() << endl;
    sphereRAW << triangulation[i].triangleToString();
    sphereRAW << "\n";
  }

  sphereRAW.close();
}

// It takes the 3 coordinates of each traingle in the octahedron and normalize
// them to the radius of the sphere
void Sphere::pointsNormalization() {
  int numTriangles = triangulation.size();
  double scaleFactor = 1;
  std::vector<Triangle> auxTriangulation;
  for (int i = 0; i < numTriangles; ++i) {
    // Coordinate #1
    if (distanceTwo3dPoints(sphereCenter, *triangulation[i].getCoord1()) !=
        sphereRadius) {
      scaleFactor =
          ((sphereRadius * 100) /
           distanceTwo3dPoints(sphereCenter, *triangulation[i].getCoord1())) /
          100;
      triangulation[i].getCoord1()->scaleCoordinate(scaleFactor);
    }
    // Coordinate #2
    if (distanceTwo3dPoints(sphereCenter, *triangulation[i].getCoord2()) !=
        sphereRadius) {
      scaleFactor =
          ((sphereRadius * 100) /
           distanceTwo3dPoints(sphereCenter, *triangulation[i].getCoord2())) /
          100;
      triangulation[i].getCoord2()->scaleCoordinate(scaleFactor);
    }
    // Coordinate #3
    if (distanceTwo3dPoints(sphereCenter, *triangulation[i].getCoord3()) !=
        sphereRadius) {
      scaleFactor =
          ((sphereRadius * 100) /
           distanceTwo3dPoints(sphereCenter, *triangulation[i].getCoord3())) /
          100;
      triangulation[i].getCoord3()->scaleCoordinate(scaleFactor);
    }
  }
}

double distanceTwo3dPoints(Coordinate3D point1, Coordinate3D point2) {
  double distance = sqrt(pow(point2.getX() - point1.getX(), 2) +
                         pow(point2.getY() - point1.getY(), 2) +
                         pow(point2.getZ() - point1.getZ(), 2));
  return distance;
}