#ifndef TRIANGULO_H_
#define TRIANGULO_H_
#include "Coordinate3D.h"
#include <string>
using namespace std;

class Triangle {
 private:
  Coordinate3D coord1;
  Coordinate3D coord2;
  Coordinate3D coord3;

 public:
  // Triangle(Coordinate3D(), Coordinate3D(), Coordinate3D());
  Triangle(double[9]);
  ~Triangle();
  string triangleToString();
};

#endif