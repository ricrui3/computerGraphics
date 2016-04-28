#ifndef SPHERE_H_
#define SPHERE_H_
#include "Triangle.h"
#include <vector>

class Sphere {
 public:
  std::vector<Triangle> triangulation;
  Sphere();
  ~Sphere();
  void generateRAW();
};

#endif