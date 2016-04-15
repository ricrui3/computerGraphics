#ifndef TRIANGULO_H_
#define TRIANGULO_H_
#include "Coordinate3D.h"

class Triangulo {
 private:
  Coordinate3D coord1;
  Coordinate3D coord2;
  Coordinate3D coord3;

 public:
  Triangulo(Coordinate3D coord1(), Coordinate3D coord2(),
            Coordinate3D coord3());
  ~Triangulo();
};

#endif