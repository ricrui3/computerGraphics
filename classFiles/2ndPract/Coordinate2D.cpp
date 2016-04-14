#include "Coordinate2D.h"

Coordinate2D::Coordinate2D(double xx, double yy) : xCoord(xx), yCoord(yy) {}

double Coordinate2D::getX() { return xCoord; }
void Coordinate2D::setX(double value) { xCoord = value; }
double Coordinate2D::getY() { return yCoord; }
void Coordinate2D::setY(double value) { yCoord = value; }