#ifndef TRIANGULO_H_
#define TRIANGULO_H_
#include "Coordinate3D.h"
#include <string>
#include <vector>
using namespace std;

class Triangle {
 private:
  Coordinate3D coord1;
  Coordinate3D coord2;
  Coordinate3D coord3;

 public:
  Triangle(Coordinate3D, Coordinate3D, Coordinate3D);
  Triangle(double[9]);
  ~Triangle();
  string triangleToString();
  void dividedTriangle(std::vector<Triangle> *triangulation);
  Coordinate3D *getCoord1() { return &coord1; }
  void setCoord1(Coordinate3D coordAux) { coord1 = coordAux; }
  Coordinate3D *getCoord2() { return &coord2; }
  void setCoord2(Coordinate3D coordAux) { coord2 = coordAux; }
  Coordinate3D *getCoord3() { return &coord3; }
  void setCoord3(Coordinate3D coordAux) { coord3 = coordAux; }
};

#endif