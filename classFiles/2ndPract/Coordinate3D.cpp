#include "Coordinate3D.h"
#include <iostream>
#include <sstream>
using namespace std;

string itos(int i);

Coordinate3D::Coordinate3D(double xx, double yy, double zz) {
  xCoord = xx;
  yCoord = yy;
  zCoord = zz;
}

double Coordinate3D::getZ() { return zCoord; }

void Coordinate3D::setZ(double value) { zCoord = value; }

std::string Coordinate3D::toString() {
  std::string valor =
      "    x: " + itos(xCoord) + " y: " + itos(yCoord) + " z:" + itos(zCoord);
  return valor;
}

string itos(int i) {
  stringstream s;
  s << i;
  return s.str();
}