#ifndef COORDINATE3D_H_
#define COORDINATE3D_H_
#include "Coordinate2D.h"
#include <string>

class Coordinate3D : public Coordinate2D {
 private:
  double zCoord;

 public:
  Coordinate3D(double = 0, double = 0, double = 0);
  double getZ();
  void setZ(double value);
  std::string toString();
};

#endif