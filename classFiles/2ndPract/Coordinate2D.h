#ifndef COORDINATE2D_H_
#define COORDINATE2D_H_

class Coordinate2D {
 protected:
  double xCoord;
  double yCoord;

 public:
  Coordinate2D(double = 0, double = 0);
  double getX();
  void setX(double value);
  double getY();
  void setY(double value);
};

#endif