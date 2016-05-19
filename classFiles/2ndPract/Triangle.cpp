#include "Triangle.h"
using namespace std;

Coordinate3D midPoint(Coordinate3D coord1, Coordinate3D coord2);

Triangle::Triangle(Coordinate3D c1, Coordinate3D c2, Coordinate3D c3) {
  coord1 = c1;
  coord2 = c2;
  coord3 = c3;
}

Triangle::Triangle(double coordinates[9]) {
  coord1.setXYZ(coordinates[0], coordinates[1], coordinates[2]);
  coord2.setXYZ(coordinates[3], coordinates[4], coordinates[5]);
  coord3.setXYZ(coordinates[6], coordinates[7], coordinates[8]);
}

Triangle::~Triangle() {}

string Triangle::triangleToString() {
  string stringCoord;
  stringCoord = coord1.toString() + coord2.toString() + coord3.toString();
  return stringCoord;
}

// Elijo un triangulo el cual va a ser dividido en 4 nuevos triangulos, el
// primer triangulo tendra como vertices:
// 1er Triangulo----(coord1, mP(coord1, coord2), mP(coord1, coord3))
// 2do Triangulo----(mP(coord1, coord2), coord2, mP(coord2, coord3))
// 3er Triangulo----(mP(coord1, coord2), mP(coord1, coord3), mP(coord2, coord3))
// 4to Tirangulo----(mP(coord1, coord3), mP(coord2, coord3), coord3)
//       -(mp())
/*
              Coord1
                /\
               /  \
     mp(c1,c2)/____\mp(c1,c3)
             /\    /\
            /  \  /  \
     Coord2/____\/____\Coord3

             mp(c2,c3)
*/
void Triangle::dividedTriangle(std::vector<Triangle> *triangulation) {
  // 1st Triangle
  (*triangulation).push_back(
      Triangle(coord1, midPoint(coord1, coord2), midPoint(coord1, coord3)));
  // 2nd Triangle
  (*triangulation).push_back(
      Triangle(midPoint(coord1, coord2), coord2, midPoint(coord2, coord3)));
  // 3rd Triangle
  (*triangulation)
      .push_back(Triangle(midPoint(coord1, coord2), midPoint(coord1, coord3),
                          midPoint(coord2, coord3)));
  // 4th Triangle
  (*triangulation).push_back(
      Triangle(midPoint(coord1, coord3), midPoint(coord2, coord3), coord3));
}

Coordinate3D midPoint(Coordinate3D coord1, Coordinate3D coord2) {
  return Coordinate3D(((coord1.getX() + coord2.getX()) / 2),
                      ((coord1.getY() + coord2.getY()) / 2),
                      ((coord1.getZ() + coord2.getZ()) / 2));
}
