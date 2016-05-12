#include "Coordinate3D.h"
#include <iostream>
#include <sstream>
using namespace std;

string dtos(double i);

Coordinate3D::Coordinate3D(double xx, double yy, double zz) {
  xCoord = xx;
  yCoord = yy;
  zCoord = zz;
}

double Coordinate3D::getZ() { return zCoord; }

void Coordinate3D::setZ(double value) { zCoord = value; }

void Coordinate3D::setXYZ(int xx, int yy, int zz) {
  xCoord = xx;
  yCoord = yy;
  zCoord = zz;
}

std::string Coordinate3D::toString() {
  std::string valor =
      " " + dtos(xCoord) + " " + dtos(yCoord) + " " + dtos(zCoord);
  return valor;
}

string dtos(double i) {
  stringstream s;
  s << i;
  return s.str();
}