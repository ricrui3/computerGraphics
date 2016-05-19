#ifndef SPHERE_H_
#define SPHERE_H_
#include "Triangle.h"
#include "Coordinate3D.h"
#include <vector>

class Sphere {
 private:
  int sphereRadius;
  Coordinate3D sphereCenter;

 public:
  std::vector<Triangle> triangulation;
  Sphere();
  ~Sphere();
  void recursiveTriangles();
  void readRawFile(char *Name);
  void generateNewRAW();
  void pointsNormalization();
};

#endif