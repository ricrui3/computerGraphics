#ifndef COORDINATE3D_H_
#define COORDINATE3D_H_
#include "Coordinate2D.h"
#include <string>

class Coordinate3D : public Coordinate2D {
 private:
  double zCoord;

 public:
  Coordinate3D(double = 0, double = 0, double = 0);
  void setXYZ(int x, int y, int z);
  double getZ();
  void setZ(double value);
  void scaleCoordinate(double scaleFactor);
  std::string toString();
};

#endif