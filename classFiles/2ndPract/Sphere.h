#ifndef SPHERE_H_
#define SPHERE_H_
#include "Triangle.h"
#include <vector>

class Sphere {
private:
	int numRecursions;
 public:
  std::vector<Triangle> triangulation;
  Sphere(int = 1);
  ~Sphere();
  void recursiveTriangles();
  void generateRAW();
};

#endif