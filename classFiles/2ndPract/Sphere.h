#ifndef SPHERE_H_
#define SPHERE_H_
#include "Triangle.h"
#include <vector>

class Sphere {
 private:
  int sphereRadius();

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