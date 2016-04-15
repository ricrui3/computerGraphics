#include "Triangle.h"

/*Triangle::Triangle(Coordinate3D c1(), Coordinate3D c2(), Coordinate3D c3()){
        coord1 = c1;
}*/

Triangle::Triangle(double coordinates[9]) {
  coord1.setXYZ(coordinates[0], coordinates[1], coordinates[2]);
  coord2.setXYZ(coordinates[3], coordinates[4], coordinates[5]);
  coord3.setXYZ(coordinates[6], coordinates[7], coordinates[8]);
}

Triangle::~Triangle() {}