#ifndef PIXEL_H_
#define PIXEL_H_

class Pixel {
 public:
  int colorR;
  int colorG;
  int colorB;
  Pixel(int = 0, int = 0, int = 0);
  ~Pixel();
  void setRGB(int cR, int cG, int cB);
  void setRGB(Pixel pixel);
};

#endif